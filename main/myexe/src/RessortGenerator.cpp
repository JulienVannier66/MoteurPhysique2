#include <RessortGenerator.hpp>

void RessortGenerator::updateForce(Vecteur3D p_point, float duration)
{
    Vecteur3D delta = p_point - m_point;
    m_object.addForceAtBodyPoint(p_point,delta.normalise() * (delta.norme() - m_Lo) * -m_K);   //je ne sais pas si il ne faut pas utiliser la fonction AddForceAtPoint plutot que celle-ci
}