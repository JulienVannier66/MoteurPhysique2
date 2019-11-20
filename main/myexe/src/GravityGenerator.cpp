#include "GravityGenerator.hpp"



void GravityGenerator::updateForce(RigidBody p_rigidbody, float duration)
{
    if (float l_m = p_rigidbody.getMasse() != 0)
    {
        p_rigidbody.addForceAtPoint(p_rigidbody.getPosition() ,gravity * l_m);  // on ajoute la force de gravite aux accumulateurs du rigidbody
    } 
}