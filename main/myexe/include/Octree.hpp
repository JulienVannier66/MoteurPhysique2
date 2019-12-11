#pragma once
#include <Rectangle.hpp>
#include <RigidBody.hpp>
#include <Vecteur3D.hpp>
#include <deque>
#include <iostream>
#include <list>
#include <math.h>
#include <queue>
#include <vector>


class Octree
{
private:
	//la région de l'octree
    Rectangle m_region;

	//la liste des objets
    std::list<RigidBody::BoundingSphere> m_objects;

    // les subdivisions de notre octree
    std::vector<Octree> m_enfants;

	//nombre de nodes actives
    int m_activeNodes = 0;

    // la taille minimale du cube.
    const int m_taille_min = 1;

    //une référence vers le parent
    Octree* m_parent;

public:
    // Constructors
    Octree()
    {
        Vecteur3D vecteur1 = Vecteur3D(0, 0, 0);
        Vecteur3D vecteur2 = Vecteur3D(0, 0, 0);

        m_objects = std::list<RigidBody::BoundingSphere>();
        m_region = Rectangle(vecteur1, vecteur2);
    }
    Octree(Rectangle p_region, std::list<RigidBody::BoundingSphere> p_objList);
    Octree(Rectangle p_region);

    // Constructeur de copie
    //Octree(const Octree& p_octree);

	//Octree& operator=(const Octree&)

    //Construction de l'octree
    void BuildTree();

	//Création d'une node à partir d'un cube et d'une liste d'objets
    Octree CreateNode(Rectangle p_region,
                      std::list<RigidBody::BoundingSphere> p_objList); 
	//Création d'une node à partir d'un cube et d'un seul objet
    Octree CreateNode(Rectangle p_region, RigidBody::BoundingSphere p_item);

};
