#include <Vecteur3D.hpp>
#include <Quaternion.hpp>

class RigidBody
{
private:
    float m_inverseMass;
    float m_masse;
    float m_linearDumping;
    Vecteur3D m_position;
    Vecteur3D m_velocite;
    //Quaternion m_orientation;
    Vecteur3D m_rotation;	// velocite angulaire
	//Matrix4 m_transforme Matrix

public:
    /*Constructeurs et destructeur*/
	RigidBody(float p_masse, float p_linearDumping, float p_position, float p_velocite, float p_rotation, Quaternion p_orientation) 
	{

	}

};