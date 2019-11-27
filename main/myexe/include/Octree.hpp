#pragma once
#include <BoundingSphere.hpp>
#include <BoundingBox.hpp>
#include <vector>
#include <queue>
using namespace std; 

class Octree
{
private:
    BoundingBox m_region;
    std::vector<BoundingSphere> m_spheres_list;

    static Queue m_pendingInsertion = new Queue();

    // OctTree[] m_childNode = new OctTree[8];
    std::vector<Octree> m_enfants;

    /// This is a bitmask indicating which child nodes are actively being used.
    /// It adds slightly more complexity, but is faster for performance since there is only one
    /// comparison instead of 8.
    byte m_activeNodes = 0;

    /// The minumum size for enclosing region is a 1x1x1 cube.
    const int taille_min = 1;

    /// this is how many frames we'll wait before deleting an empty tree branch. Note that this is
    /// not a constant. The maximum lifespan doubles every time a node is reused, until it hits a
    /// hard coded constant of 64
    int m_maxLifespan = 8; //
    int m_curLife = -1;    // this is a countdown time showing how much time we have left to live

    /// A reference to the parent node is nice to have when we're trying to do a tree update.
    OctTree _parent;
    static bool m_treeReady =
        false; // the tree has a few objects which need to be inserted before it is complete
    static bool m_treeBuilt = false; // there is no pre-existing tree yet.

public:

	//Constructors
    Octree();
    Octree(BoundingBox region, List objList);
};
