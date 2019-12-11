#pragma once
#include <Vecteur3D.hpp>

class Rectangle
{
private:
    Vecteur3D m_center;
    Vecteur3D m_demiLongueur;

    Vecteur3D Max = m_center + m_demiLongueur;
    Vecteur3D Min = m_center - m_demiLongueur;

public:
    Rectangle() {}
    Rectangle(Vecteur3D p_center, Vecteur3D p_demiLongueur)
    {
        m_center = p_center;
        m_demiLongueur = p_demiLongueur;
    }
    ~Rectangle() {}

    Vecteur3D getMax() { return Max; }
    Vecteur3D getMin() { return Min; }
    Vecteur3D getCenter() { return m_center; }
    Vecteur3D getDemiLongueur() { return m_demiLongueur; }
};