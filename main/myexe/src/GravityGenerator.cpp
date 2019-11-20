#include "GravityGenerator.hpp"



void GravityGenerator::updateForce(RigidBody p_rigidbody, float duration)
{
    if (float l_m = p_rigidbody.getMasse() != 0)
    {
        p_rigidbody.addForceAtPoint(gravity * l_m);  // on ajoute la force de gravite aux accumulateurs du rigidbody
    } 
    std::cout << count << std::endl;
}