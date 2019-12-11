#include <Octree.hpp>

/*Note: we want to avoid allocating memory for as long as possible since there can be lots of
 * nodes.*/
///
/// Creates an oct tree which encloses the given region and contains the provided objects.
///

/// The bounding region for the oct tree.
/// The list of objects contained within the bounding region
Octree::Octree(Rectangle p_region, std::list<RigidBody::BoundingSphere> p_objList)
{
    m_region = p_region;
    m_objects = p_objList;
}

///
/// Creates an octTree with a suggestion for the bounding region containing the items.
///

/// The suggested dimensions for the bounding region.
/// Note: if items are outside this region, the region will be automatically resized.
Octree::Octree(Rectangle p_region)
{
    m_region = p_region;
    m_objects = std::list<RigidBody::BoundingSphere>();
}

Octree::Octree(Octree& p_octree)
{
    m_region = p_octree.m_region;
    m_objects = p_octree.m_objects;
    m_enfants = p_octree.m_enfants;
    m_activeNodes = p_octree.m_activeNodes;
	m_parent = p_octree.m_parent;
}

// void Octree::UpdateTree()
//{
//    if (!m_treeBuilt)
//    {
//        while (m_pendingInsertion.size() != 0)
//        {
//            m_objects.push_back(m_pendingInsertion.front());
//            m_pendingInsertion.pop();
//        }
//        BuildTree();
//    }
//    else
//    {
//        while (m_pendingInsertion.size() != 0) { Insert(m_pendingInsertion.pop()); }
//    }
//    m_treeReady = true;
//}

void Octree::BuildTree() // complete & tested
{
    // terminate the recursion if we're a leaf node
    if (m_objects.size() <= 2) return;

    Vecteur3D dimensions = m_region.getMax() - m_region.getMin();

    Vecteur3D vecteur0 = Vecteur3D(0, 0, 0);

    // Check to see if the dimensions of the box are greater than the minimum dimensions
    if (dimensions.getX() <= m_taille_min && dimensions.getY() <= m_taille_min &&
        dimensions.getZ() <= m_taille_min)
    { return; }

    Vecteur3D half = dimensions * 0.5f;
    Vecteur3D center = m_region.getMin() + half;

    // Create subdivided regions for each octant
    std::vector<Rectangle> octant;
    // Rectangle[] octant = new Rectangle[8];
    octant.push_back(Rectangle(m_region.getMin(), center));
    octant.push_back(
        Rectangle(Vecteur3D(center.getX(), m_region.getMin().getY(), m_region.getMin().getZ()),
                  Vecteur3D(m_region.getMax().getX(), center.getY(), center.getZ())));
    octant.push_back(
        Rectangle(Vecteur3D(center.getX(), m_region.getMin().getY(), center.getZ()),
                  Vecteur3D(m_region.getMax().getX(), center.getY(), m_region.getMax().getZ())));
    octant.push_back(
        Rectangle(Vecteur3D(m_region.getMin().getX(), m_region.getMin().getY(), center.getZ()),
                  Vecteur3D(center.getX(), center.getY(), m_region.getMax().getZ())));
    octant.push_back(
        Rectangle(Vecteur3D(m_region.getMin().getX(), center.getY(), m_region.getMin().getZ()),
                  Vecteur3D(center.getX(), m_region.getMax().getY(), center.getZ())));
    octant.push_back(
        Rectangle(Vecteur3D(center.getX(), center.getY(), m_region.getMin().getZ()),
                  Vecteur3D(m_region.getMax().getX(), m_region.getMax().getY(), center.getZ())));
    octant.push_back(Rectangle(center, m_region.getMax()));
    octant.push_back(
        Rectangle(Vecteur3D(m_region.getMin().getX(), center.getY(), center.getZ()),
                  Vecteur3D(center.getX(), m_region.getMax().getY(), m_region.getMax().getZ())));

    // This will contain all of our objects which fit within each respective octant.
    std::vector<std::vector<RigidBody::BoundingSphere>> octList;

    for (RigidBody::BoundingSphere obj : m_objects)
    {
        if (obj.rayon != 0)
        {
            for (int i = 0; i < 8; i++)
            {
                Vecteur3D vec1 = octant.at(i).getCenter();
                Vecteur3D vec2 = obj.centre;

                float dist = ((vec2.getX() - vec1.getX()) * (vec2.getX() - vec1.getX()) +
                              (vec2.getY() - vec1.getY()) * (vec2.getY() - vec1.getY()) +
                              (vec2.getZ() - vec1.getZ()) * (vec2.getZ() - vec1.getZ()));
                // Si la sphere est dans le cube
                if (dist >= (octant.at(i).getDemiLongueur().getX() * sqrt(3) + obj.rayon))
                {
                    // On ajoute l'objet dans la liste
                    octList.at(i).push_back(obj);
                    break;
                }
            }
        }
    }

    // Create child nodes where there are items contained in the bounding region
    for (int i = 0; i < 8; i++)
    {
        if (octList.at(i).size() != 0)
        {
            std::list<RigidBody::BoundingSphere> newlist;
            for (RigidBody::BoundingSphere obj : octList.at(i)) { newlist.push_back(obj); }

            m_enfants.at(i) = CreateNode(octant.at(i), newlist);
            m_activeNodes |= (1 << i);
            m_enfants.at(i).BuildTree();
        }
    }

    // m_treeBuilt = true;
    // m_treeReady = true;
}

Octree Octree::CreateNode(Rectangle region,
                          std::list<RigidBody::BoundingSphere> objList) // complete & tested
{
    if (objList.size() == 0) return Octree();
    Octree ret = Octree(region, objList);
    ret.m_parent = this;
    return ret;
}

Octree Octree::CreateNode(Rectangle p_region, RigidBody::BoundingSphere p_item)
{
    std::list<RigidBody::BoundingSphere> objList; // sacrifice potential CPU time for a smaller
                                                  // memory footprint
    objList.push_back(p_item);
    Octree ret = Octree(p_region, objList);
    ret.m_parent = this;
    return ret;
}

/// <summary>
/// A tree has already been created, so we're going to try to insert an item into the tree without
/// rebuilding the whole thing
/// </summary>
// bool Octree::Insert(RigidBody::BoundingSphere p_item)
//{
//    /*if the current node is an empty leaf node, just insert and leave it.*/
//    // if (m_objects.Count == 0 && m_activeNodes == 0)
//    if (AllTreeObjects.Count == 0)
//    {
//        m_objects.push_back(p_item);
//        return true;
//    }
//
//    // Check to see if the dimensions of the box are greater than the minimum dimensions.
//    // If we're at the smallest size, just insert the item here. We can't go any lower!
//    Vecteur3D dimensions = m_region.getMax() - m_region.getMin();
//    if (dimensions.getX() <= m_taille_min && dimensions.getY() <= m_taille_min &&
//        dimensions.getZ() <= m_taille_min)
//    {
//        m_objects.push_back(p_item);
//        return true;
//    }
//
//    // The object won't fit into the current region, so it won't fit into any child regions.
//    // therefore, try to push it up the tree. If we're at the root node, we need to resize the
//    // whole tree.
//    if (m_region.Contains(Item.EnclosingSphere) != ContainmentType.Contains)
//    {
//        if (this._parent != null)
//            return this._parent.Insert(Item);
//        else
//            return false;
//    }
//
//    // At this point, we at least know this region can contain the object but there are child
//    nodes.
//    // Let's try to see if the object will fit within a subregion of this region.
//
//    Vecteur3D half = dimensions * 0.5f;
//    Vecteur3D center = m_region.getMin() + half;
//
//    // Find or create subdivided regions for each octant in the current region
//    BoundingBox[] childOctant = new BoundingBox[8];
//    childOctant[0] = (m_childNode[0] != null) ? m_childNode[0].m_region
//                                              : new BoundingBox(m_region.getMin(), center);
//    childOctant[1] =
//        (m_childNode[1] != null)
//            ? m_childNode[1].m_region
//            : new BoundingBox(
//                  new Vecteur3D(center.getX(), m_region.getMin().getY(),
//                  m_region.getMin().getZ()), new Vecteur3D(m_region.getMax().getX(),
//                  center.getY(), center.getZ()));
//    childOctant[2] =
//        (m_childNode[2] != null)
//            ? m_childNode[2].m_region
//            : new BoundingBox(
//                  new Vecteur3D(center.getX(), m_region.getMin().getY(), center.getZ()),
//                  new Vecteur3D(m_region.getMax().getX(), center.getY(),
//                  m_region.getMax().getZ()));
//    childOctant[3] =
//        (m_childNode[3] != null)
//            ? m_childNode[3].m_region
//            : new BoundingBox(
//                  new Vecteur3D(m_region.getMin().getX(), m_region.getMin().getY(),
//                  center.getZ()), new Vecteur3D(center.getX(), center.getY(),
//                  m_region.getMax().getZ()));
//    childOctant[4] =
//        (m_childNode[4] != null)
//            ? m_childNode[4].m_region
//            : new BoundingBox(
//                  new Vecteur3D(m_region.getMin().getX(), center.getY(),
//                  m_region.getMin().getZ()), new Vecteur3D(center.getX(),
//                  m_region.getMax().getY(), center.getZ()));
//    childOctant[5] =
//        (m_childNode[5] != null)
//            ? m_childNode[5].m_region
//            : new BoundingBox(
//                  new Vecteur3D(center.getX(), center.getY(), m_region.getMin().getZ()),
//                  new Vecteur3D(m_region.getMax().getX(), m_region.getMax().getY(),
//                  center.getZ()));
//    childOctant[6] = (m_childNode[6] != null) ? m_childNode[6].m_region
//                                              : new BoundingBox(center, m_region.getMax());
//    childOctant[7] =
//        (m_childNode[7] != null)
//            ? m_childNode[7].m_region
//            : new BoundingBox(
//                  new Vecteur3D(m_region.getMin().getX(), center.getY(), center.getZ()),
//                  new Vecteur3D(center.getX(), m_region.getMax().getY(),
//                  m_region.getMax().getZ()));
//
//    // First, is the item completely contained within the root bounding box?
//    // note2: I shouldn't actually have to compensate for this. If an object is out of our
//    // predefined bounds, then we have a problem/error.
//    //          Wrong. Our initial bounding box for the terrain is constricting its height to the
//    //          highest peak. Flying units will be above that.
//    //             Fix: I resized the enclosing box to 256x256x256. This should be sufficient.
//    if (Item.EnclosingBox.Max != Item.EnclosingBox.Min &&
//        m_region.Contains(Item.EnclosingBox) == ContainmentType.Contains)
//    {
//        bool found = false;
//        // we will try to place the object into a child node. If we can't fit it in a child node,
//        // then we insert it into the current node object list.
//        for (int a = 0; a < 8; a++)
//        {
//            // is the object fully contained within a quadrant?
//            if (childOctant[a].Contains(Item.EnclosingBox) == ContainmentType.Contains)
//            {
//                if (m_childNode[a] != null)
//                {
//                    return m_childNode[a].Insert(Item); // Add the item into that tree and let the
//                                                        // child tree figure out what to do with
//                                                        it
//                }
//                else
//                {
//                    m_childNode[a] =
//                        CreateNode(childOctant[a], Item); // create a new tree node with the item
//                    m_activeNodes |= (byte)(1 << a);
//                }
//                found = true;
//            }
//        }
//
//        // we couldn't fit the item into a smaller box, so we'll have to insert it in this region
//        if (!found)
//        {
//            m_objects.Add(Item);
//            return true;
//        }
//    }
//    else if (Item.EnclosingSphere.Radius != 0 &&
//             m_region.Contains(Item.EnclosingSphere) == ContainmentType.Contains)
//    {
//        bool found = false;
//        // we will try to place the object into a child node. If we can't fit it in a child node,
//        // then we insert it into the current node object list.
//        for (int a = 0; a < 8; a++)
//        {
//            // is the object contained within a child quadrant?
//            if (childOctant[a].Contains(Item.EnclosingSphere) == ContainmentType.Contains)
//            {
//                if (m_childNode[a] != null)
//                {
//                    return m_childNode[a].Insert(Item); // Add the item into that tree and let the
//                                                        // child tree figure out what to do with
//                                                        it
//
//                }
//                else
//                {
//                    m_childNode[a] =
//                        CreateNode(childOctant[a], Item); // create a new tree node with the item
//                    m_activeNodes |= (1 << a);
//                }
//                found = true;
//            }
//        }
//
//        // we couldn't fit the item into a smaller box, so we'll have to insert it in this region
//        if (!found)
//        {
//            m_objects.push_back(p_item);
//            return true;
//        }
//    }
//
//    // either the item lies outside of the enclosed bounding box or it is intersecting it. Either
//    // way, we need to rebuild the entire tree by enlarging the containing bounding box
//    return false;
//}
