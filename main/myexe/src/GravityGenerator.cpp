#include "GravityGenerator.hpp"

void GravityGenerator::updateForce(RigidBody p_rigidbody, float duration)
{
    if (float l_m = p_rigidbody.getMasse() != 0) { p_rigidbody.addForce(gravity * l_m); }
    std::cout << count << std::endl;
    count++;
}