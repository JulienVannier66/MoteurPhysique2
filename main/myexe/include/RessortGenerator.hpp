#pragma once
#include <Vecteur3D.hpp>
#include <RigidBody.hpp>

/*Cette classe permet d'appliquer une force de Hooke entre deux particules*/

class RessortGenerator 
{
private:
    Vecteur3D m_point;         // Point d'attache du ressort
    RigidBody m_object;			//objet auquel est attaché le ressort	
    float m_K = 0;                    // Constante propre au ressort
    float m_Lo = 1;                   // Longueur du ressort au repos

public:
    // Constructeurs & Destructeur
    RessortGenerator():m_point(1,1,1) {}
    RessortGenerator(Vecteur3D p_point, RigidBody p_object,const float& p_K, const float& p_Lo)
        : m_point(p_point),m_object(p_object), m_K(p_K), m_Lo(p_Lo)
    {}
    RessortGenerator(RessortGenerator& p_ressort)
        : m_point(p_ressort.m_point),m_object(p_ressort.m_object), m_K(p_ressort.m_K), m_Lo(p_ressort.m_Lo)
    {}
    ~RessortGenerator() {}

    // Getters
    Vecteur3D getPoint() { return m_point; }
    float getK() { return m_K; }
    float getLo() { return m_Lo; }
    RigidBody getObject() { return m_object; }

    // Setters
    void setParticule(Vecteur3D p_point) { m_point = p_point; }
    void setK(float p_K) { m_K = p_K; }
    void setLo(float p_Lo) {m_Lo = p_Lo; }
    void setObject(RigidBody p_object) { m_object = p_object; }

    void updateForce(Vecteur3D p_point, float duration); // Ajout de la force generee par le ressort a la particule
};