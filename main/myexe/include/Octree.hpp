#pragma once
#include <BoundingBox.hpp>
#include <BoundingSphere.hpp>
#include <iostream>       
#include <deque>         
#include <list>          
#include <queue>  
#include <RigidBody.hpp>


typedef unsigned char BYTE;

class Octree
{
private:
    BoundingBox m_region;
    //std::vector<BoundingSphere> m_spheres_list; // liste des objets présent dans la bounding box
    std::list<RigidBody> m_objects; 

    static std::queue<RigidBody> m_pendingInsertion;

    // OctTree[] m_childNode = new OctTree[8];
    // les subdivisions de notre octree
    std::vector<Octree> m_enfants;

    /// This is a bitmask indicating which child nodes are actively being used.
    /// It adds slightly more complexity, but is faster for performance since there is only one
    /// comparison instead of 8.
    BYTE m_activeNodes = 0;

    /// The minumum size for enclosing region is a 1x1x1 cube.
    const int m_taille_min = 1;

    /// this is how many frames we'll wait before deleting an empty tree branch. Note that this is
    /// not a constant. The maximum lifespan doubles every time a node is reused, until it hits a
    /// hard coded constant of 64
    int m_maxLifespan = 8; //
    int m_curLife = -1;    // this is a countdown time showing how much time we have left to live

    /// A reference to the parent node is nice to have when we're trying to do a tree update.
    Octree m_parent;
    static bool m_treeReady = false; // the tree has a few objects which need to be inserted before it is complete
    static bool m_treeBuilt = false; // there is no pre-existing tree yet.

public:
    // Constructors
    Octree()
    {
        m_objects = new std::list<RigidBody>();
        m_region = new BoundingBox(Vector3.Zero, Vector3.Zero);
        m_curLife = -1;
    };
    Octree(BoundingBox p_region, std::list<RigidBody> p_objList);
    Octree(BoundingBox p_region);

    /// Processes all pending insertions by inserting them into the tree.
    void UpdateTree();

	/// Naively builds an oct tree from scratch.
    void BuildTree();
};
