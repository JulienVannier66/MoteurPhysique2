#include <RessortGenerator.hpp>

void RessortGenerator::updateForce()
{
    m_point1.localToWorld(m_object.getTransformMatrice());
    m_point2.localToWorld(m_object.getTransformMatrice());
    Vecteur3D delta = m_point1 - m_point2;
    m_object.addForceAtPoint(m_point1,delta.normalise() * (delta.norme() - m_Lo) * -m_K);   //je ne sais pas si il ne faut pas utiliser la fonction AddForceAtPoint plutot que celle-ci
}