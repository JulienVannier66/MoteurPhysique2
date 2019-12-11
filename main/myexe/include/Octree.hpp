#pragma once
#include <RigidBody.hpp>
#include <Rectangle.hpp>
#include <Vecteur3D.hpp>
#include <deque>
#include <iostream>
#include <list>
#include <vector>
#include <queue>

typedef unsigned char BYTE;

class Octree
{
private:
    Rectangle m_region;
    // std::vector<BoundingSphere> m_spheres_list; // liste des objets présent dans la bounding box
    std::vector<RigidBody::BoundingSphere> m_objects;

    static std::queue<RigidBody::BoundingSphere> m_pendingInsertion;

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
    Octree& m_parent;

    static bool m_treeReady = false; // the tree has a few objects which need to be inserted before it is complete
    static bool m_treeBuilt = false; // there is no pre-existing tree yet.

public:
    // Constructors
    Octree(){
        Vecteur3D vecteur1 = Vecteur3D(0, 0, 0);
        Vecteur3D vecteur2 = Vecteur3D(0, 0, 0);
        //m_parent = ;
		 
        m_objects = std::vector<RigidBody::BoundingSphere>();
        m_region = Rectangle(vecteur1, vecteur2);
        m_curLife = -1;
    }
    Octree(Rectangle p_region, std::vector<RigidBody::BoundingSphere> p_objList);
    Octree(Rectangle p_region);

    /// Processes all pending insertions by inserting them into the tree.
    void UpdateTree();

    /// Naively builds an oct tree from scratch.
    void BuildTree();

    Octree CreateNode(Rectangle p_region, std::vector<RigidBody::BoundingSphere> p_objList); // complete & tested

    Octree CreateNode(Rectangle p_region, RigidBody::BoundingSphere p_item);

	//bool Octree::Insert<T>(T Item) where T : Physical;
};
