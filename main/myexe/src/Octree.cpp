#include <Octree.hpp>

/*Note: we want to avoid allocating memory for as long as possible since there can be lots of
 * nodes.*/
///
/// Creates an oct tree which encloses the given region and contains the provided objects.
///

/// The bounding region for the oct tree.
/// The list of objects contained within the bounding region
Octree::Octree(BoundingBox p_region, std::list<RigidBody> p_objList)
{
    m_region = p_region;
    m_objects = p_objList;
    m_curLife = -1;
}

///
/// Creates an octTree with a suggestion for the bounding region containing the items.
///

/// The suggested dimensions for the bounding region.
/// Note: if items are outside this region, the region will be automatically resized.
Octree::Octree(BoundingBox p_region)
{
    m_region = p_region;
    m_objects = std::list<RigidBody>();
    m_curLife = -1;
}

void Octree::UpdateTree()
{
    if (!m_treeBuilt)
    {
        while (m_pendingInsertion.Count != 0) m_objects.Add(m_pendingInsertion.Dequeue());
        BuildTree();
    }
    else
    {
        while (m_pendingInsertion.Count != 0) Insert(m_pendingInsertion.Dequeue());
    }
    m_treeReady = true;
}

void Octree::BuildTree() // complete & tested
{
    // terminate the recursion if we're a leaf node
    if (m_objects.Count <= 1) return;

    Vector3 dimensions = m_region.Max - m_region.Min;

    if (dimensions == Vector3.Zero)
    {
        FindEnclosingCube();
        dimensions = m_region.Max - m_region.Min;
    }

    // Check to see if the dimensions of the box are greater than the minimum dimensions
    if (dimensions.X <= MIN_SIZE && dimensions.Y <= MIN_SIZE && dimensions.Z <= MIN_SIZE)
    { return; }

    Vector3 half = dimensions / 2.0f;
    Vector3 center = m_region.Min + half;

    // Create subdivided regions for each octant
    BoundingBox[] octant = new BoundingBox[8];
    octant[0] = new BoundingBox(m_region.Min, center);
    octant[1] = new BoundingBox(new Vector3(center.X, m_region.Min.Y, m_region.Min.Z),
                                new Vector3(m_region.Max.X, center.Y, center.Z));
    octant[2] = new BoundingBox(new Vector3(center.X, m_region.Min.Y, center.Z),
                                new Vector3(m_region.Max.X, center.Y, m_region.Max.Z));
    octant[3] = new BoundingBox(new Vector3(m_region.Min.X, m_region.Min.Y, center.Z),
                                new Vector3(center.X, center.Y, m_region.Max.Z));
    octant[4] = new BoundingBox(new Vector3(m_region.Min.X, center.Y, m_region.Min.Z),
                                new Vector3(center.X, m_region.Max.Y, center.Z));
    octant[5] = new BoundingBox(new Vector3(center.X, center.Y, m_region.Min.Z),
                                new Vector3(m_region.Max.X, m_region.Max.Y, center.Z));
    octant[6] = new BoundingBox(center, m_region.Max);
    octant[7] = new BoundingBox(new Vector3(m_region.Min.X, center.Y, center.Z),
                                new Vector3(center.X, m_region.Max.Y, m_region.Max.Z));

    // This will contain all of our objects which fit within each respective octant.
    List[] octList = new List[8];

    for (int i = 0; i < 8; i++) octList = new List();

    // this list contains all of the objects which got moved down the tree and can be delisted from
    // this node.
    List delist = new List();

    foreach (Physical obj in m_objects)
    {
        if (obj.BoundingBox.Min != obj.BoundingBox.Max)
        {
            for (int a = 0; a < 8; a++)
            {
                if (octant[a].Contains(obj.BoundingBox) == ContainmentType.Contains)
                {
                    octList[a].Add(obj);
                    delist.Add(obj);
                    break;
                }
            }
        }
        else if (obj.BoundingSphere.Radius != 0)
        {
            for (int a = 0; a < 8; a++)
            {
                if (octant[a].Contains(obj.BoundingSphere) == ContainmentType.Contains)
                {
                    octList[a].Add(obj);
                    delist.Add(obj);
                    break;
                }
            }
        }
    }

    // delist every moved object from this node.
    foreach (Physical obj in delist)
        m_objects.Remove(obj);

    // Create child nodes where there are items contained in the bounding region
    for (int a = 0; a < 8; a++)
    {
        if (octList[a].Count != 0)
        {
            m_childNode[a] = CreateNode(octant[a], octList[a]);
            m_activeNodes |= (byte)(1 << a);
            m_childNode[a].BuildTree();
        }
    }

    m_treeBuilt = true;
    m_treeReady = true;
}
