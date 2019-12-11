#pragma once
#include <RigidBody.hpp>
#include <Rectangle.hpp>
#include <Vecteur3D.hpp>
#include <deque>
#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <math.h>

//typedef unsigned char BYTE;

class Octree
{
private:
    Rectangle m_region;
    std::list<RigidBody::BoundingSphere> m_objects;

    // les subdivisions de notre octree
    std::vector<Octree> m_enfants;

    /// This is a bitmask indicating which child nodes are actively being used.
    /// It adds slightly more complexity, but is faster for performance since there is only one
    /// comparison instead of 8.
    int m_activeNodes = 0;

    /// The minumum size for enclosing region is a 1x1x1 cube.
    const int m_taille_min = 1;

    /// A reference to the parent node is nice to have when we're trying to do a tree update.
    Octree* m_parent;

public:
    // Constructors
    Octree(){
        Vecteur3D vecteur1 = Vecteur3D(0, 0, 0);
        Vecteur3D vecteur2 = Vecteur3D(0, 0, 0);
		 
        m_objects = std::list<RigidBody::BoundingSphere>();
        m_region = Rectangle(vecteur1, vecteur2);
    }
    Octree(Rectangle p_region, std::list<RigidBody::BoundingSphere> p_objList);
    Octree(Rectangle p_region);

    /// Naively builds an oct tree from scratch.
    void BuildTree();

    Octree CreateNode(Rectangle p_region, std::list<RigidBody::BoundingSphere> p_objList); // complete & tested

    Octree CreateNode(Rectangle p_region, RigidBody::BoundingSphere p_item);
};
