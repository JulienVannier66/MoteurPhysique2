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

            m_enfants.push_back(CreateNode(octant.at(i), newlist));
            m_activeNodes |= (1 << i);
            m_enfants.at(i).BuildTree();
        }
    }

}

Octree Octree::CreateNode(Rectangle region,
                          std::list<RigidBody::BoundingSphere> objList) 
{
    if (objList.size() == 0) return Octree();
    Octree ret = Octree(region, objList);
    ret.m_parent = this;
    return ret;
}

Octree Octree::CreateNode(Rectangle p_region, RigidBody::BoundingSphere p_item)
{
    std::list<RigidBody::BoundingSphere> objList;                                                
    objList.push_back(p_item);
    Octree ret = Octree(p_region, objList);
    ret.m_parent = this;
    return ret;
}

