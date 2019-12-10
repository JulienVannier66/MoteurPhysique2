#pragma once
#include <Primitive.hpp>

class Box : public Primitive
{
private:
    Vecteur3D m_demiLongueur = Vecteur3D(0.5f, 0.5f, 0.5f);

public:
    Box() : Primitive()
    {
        std::cout << "toto" << std::endl;
        setBoundingSphere(getBody()->getPosition(),
                                           sqrt(pow(m_demiLongueur.getX(), 2) +
                                                pow(m_demiLongueur.getY(), 2) +
                                                pow(m_demiLongueur.getZ(), 2)) /
                                               2);
    }

    Box(RigidBody* p_body, Matrix4 p_offset, float p_demi1, float p_demi2, float p_demi3)
        : Primitive(p_body, p_offset)
    {

        m_demiLongueur.setX(p_demi1);
        m_demiLongueur.setY(p_demi2);
        m_demiLongueur.setZ(p_demi3);
        setBoundingSphere(getBody()->getPosition(),
                          sqrt(pow(m_demiLongueur.getX(), 2) + pow(m_demiLongueur.getY(), 2) +
                               pow(m_demiLongueur.getZ(), 2)) /
                              2);
    }

    Box(Box& p_box) : Primitive(p_box.getBody(), p_box.getOffset())
    {

        m_demiLongueur.setX(p_box.m_demiLongueur.getX());
        m_demiLongueur.setY(p_box.m_demiLongueur.getY());
        m_demiLongueur.setZ(p_box.m_demiLongueur.getZ());
        setBoundingSphere(p_box.getBody()->getPosition(),
                          sqrt(pow(p_box.getDemiLongueur().getX(), 2) +
                               pow(p_box.getDemiLongueur().getY(), 2) +
                               pow(p_box.getDemiLongueur().getZ(), 2)) /
                              2);
    }

    ~Box() {}

    void setDemiLongueur(float p_demi1, float p_demi2, float p_demi3)
    {
        m_demiLongueur.setX(p_demi1);
        m_demiLongueur.setY(p_demi2);
        m_demiLongueur.setZ(p_demi3);
    }

    Vecteur3D getDemiLongueur() { return m_demiLongueur; }
};