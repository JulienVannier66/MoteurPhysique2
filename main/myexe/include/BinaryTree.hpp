#pragma once
#include <vector>
#include <BoundingSphere.hpp>

class BinaryTree
{
private:
    std::vector<BoundingSphere> m_spheres;
	//Je sais pas encore s'il vaut mieux associer chaque BoundingSphere a chaque objet ou faire plein de liste différentes
	//std::vector<Primitive> m_primitives; 

	BinaryTree m_left;
    BinaryTree m_right;

	BinaryTree m_parent;

	int m_numObjects = 2;
	
public:
};