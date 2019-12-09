#pragma once
#include <Vecteur3D.hpp>

class Contact
{
private:
    Vecteur3D m_contactPoint;
    Vecteur3D m_contactNormal;
    float m_penetration;

public:
    Contact() : m_contactNormal(), m_contactPoint(), m_penetration(0) {}

    Contact(Vecteur3D p_contactPoint, Vecteur3D p_contactNormal, float p_penetration)
        : m_contactNormal(p_contactPoint)
        , m_contactPoint(p_contactNormal)
        , m_penetration(p_penetration)
    {}

    Contact(Contact& p_contact)
        : m_contactNormal(p_contact.m_contactNormal)
        , m_contactPoint(p_contact.m_contactPoint)
        , m_penetration(p_contact.m_penetration)
    {}

    Vecteur3D getPoint() { return m_contactPoint; }
    Vecteur3D getNormal() { return m_contactNormal; }
    float getPenetration() { return m_penetration; }

    void setPoint(Vecteur3D p_vec) { m_contactPoint = p_vec; }
    void setNormal(Vecteur3D p_vec) { m_contactNormal = p_vec; }
    void setPenetration(float p_pen) { m_penetration = p_pen; }
};