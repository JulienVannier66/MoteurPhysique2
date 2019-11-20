#pragma once
#include <Vecteur3D.hpp>
#include <RigidBody.hpp>

/*Cette classe permet d'appliquer une force de Hooke entre deux particules*/

class RessortGenerator 
{
private:
    Vecteur3D m_point1;         // Point d'attache du ressort au rigidbody
    Vecteur3D m_point2;			// Point d'attache du ressort à l'ancre
    RigidBody m_object;			//objet auquel est attaché le ressort	
    float m_K = 0;                    // Constante propre au ressort
    float m_Lo = 1;                   // Longueur du ressort au repos

public:
    // Constructeurs & Destructeur
    RessortGenerator(){}
    RessortGenerator(Vecteur3D p_point1, Vecteur3D p_point2, RigidBody p_object, const float& p_K,
                     const float& p_Lo)
        : m_point1(p_point1), m_point2(p_point2), m_object(p_object), m_K(p_K), m_Lo(p_Lo)
    {}
    RessortGenerator(RessortGenerator& p_ressort)
        : m_point1(p_ressort.m_point1)
        , m_point2(p_ressort.m_point2)
        , m_object(p_ressort.m_object)
        , m_K(p_ressort.m_K)
        , m_Lo(p_ressort.m_Lo)
    {}
    ~RessortGenerator() {}

    // Getters
    Vecteur3D getPoint1() { return m_point1; }
    Vecteur3D getPoint2() { return m_point2; }
    float getK() { return m_K; }
    float getLo() { return m_Lo; }
    RigidBody getObject() { return m_object; }

    // Setters
    void setPoint1(Vecteur3D p_point) { m_point1 = p_point; }
    void setPoint2(Vecteur3D p_point) { m_point2 = p_point; }
    void setK(float p_K) { m_K = p_K; }
    void setLo(float p_Lo) {m_Lo = p_Lo; }
    void setObject(RigidBody p_object) { m_object = p_object; }

    void updateForce(); // Ajout de la force generee par le ressort a la particule
};