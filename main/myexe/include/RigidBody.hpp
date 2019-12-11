#pragma once
#include <Matrix3.hpp>
#include <Matrix4.hpp>
#include <Quaternion.hpp>
#include <Vecteur3D.hpp>

class RigidBody
{
private:
    float m_inverseMass = NULL;
    float m_masse;
    float m_linearDumping;
    float m_angularDumping;
    Vecteur3D m_position;
    Vecteur3D m_velocite;
    Quaternion m_orientation;
    Vecteur3D m_rotation;    // velocite angulaire
    Vecteur3D m_forceAccum;  // Vecteur forces accumulees
    Vecteur3D m_torqueAccum; // Vecteur forces accumulees
    Matrix4 m_transforme;
    Matrix3 m_inverseInertiatensor;

    bool t = true;

public:
    struct BoundingSphere
    {
        Vecteur3D centre;
        float rayon;
    };

    /*Constructeurs et destructeur*/

    // constructeur par defaut
    RigidBody()
        : m_masse(1)
        , m_inverseMass(1)
        , m_linearDumping(1)
        , m_angularDumping(1)
        , m_position(0, 0, 0)
        , m_velocite(0, 0, 0)
        , m_orientation(1, 0, 0, 0)
        , m_rotation(0, 0, 0)
        , m_forceAccum(0, 0, 0)
        , m_torqueAccum(0, 0, 0)
        , m_transforme()
        , m_inverseInertiatensor()
    {}

    // constructeur value
    RigidBody(float p_masse, float p_linearDumping, float p_angularDumpling, Vecteur3D p_position,
              Vecteur3D p_velocite, Vecteur3D p_rotation, Quaternion p_orientation,
              Matrix4 p_transforme)
        : m_masse(p_masse)
        , m_linearDumping(p_linearDumping)
        , m_angularDumping(p_angularDumpling)
        , m_position(p_position)
        , m_velocite(p_velocite)
        , m_rotation(p_rotation)
        , m_orientation(p_orientation)
        , m_transforme(p_transforme)
        , m_forceAccum(0, 0, 0)
        , m_torqueAccum(0, 0, 0)
        , m_inverseInertiatensor()
    {
        setMasse(p_masse);
    }

    // constructeur de copie
    RigidBody(RigidBody& p_rig)
        : m_masse(p_rig.m_masse)
        , m_inverseMass(p_rig.m_inverseMass)
        , m_linearDumping(p_rig.m_linearDumping)
        , m_angularDumping(p_rig.m_angularDumping)
        , m_position(p_rig.m_position)
        , m_velocite(p_rig.m_velocite)
        , m_rotation(p_rig.m_rotation)
        , m_orientation(p_rig.m_orientation)
        , m_forceAccum(p_rig.m_forceAccum)
        , m_torqueAccum(p_rig.m_torqueAccum)
        , m_transforme(p_rig.m_transforme)
        , m_inverseInertiatensor(p_rig.m_inverseInertiatensor)
    {}

    /*Setter*/
    void setMasse(float p_masse)
    {
        m_masse = p_masse;
        if (m_masse != 0) { m_inverseMass = 1 / m_masse; }
        else
            std::cout << "la masse etant nulle il est impossible de l'inverser" << std::endl;
    }

    void setLinearDumping(float p_linearDumping) { m_linearDumping = p_linearDumping; }

    void setAngularDumping(float p_angularDumping) { m_angularDumping = p_angularDumping; }

    void setPosition(Vecteur3D p_position) { m_position = p_position; }

    void setVelocite(Vecteur3D p_velocite) { m_velocite = p_velocite; }

    void setRotation(Vecteur3D p_rotation) { m_rotation = p_rotation; }

    void setOrientation(Quaternion p_orientation) { m_orientation = p_orientation; }

    /*Getter*/
    float getMasse() { return m_masse; }
    float getInverseMasse() { return m_inverseMass; }
    float getLinearDumping() { return m_linearDumping; }
    float getAngularDumping() { return m_angularDumping; }
    Vecteur3D getPosition() { return m_position; }
    Vecteur3D getVelocite() { return m_velocite; }
    Vecteur3D getRotation() { return m_rotation; }
    Quaternion getOrientation() { return m_orientation; }
    Matrix4 getTransformMatrice() { return m_transforme; }

    /*Ajoute une force � l'accumulateur de force*/
    void addForce(Vecteur3D p_force);

    /*Ajoute une couple � l'accumulateur de couple*/
    void addTorque(Vecteur3D p_torque);

    /*vide les deux accumulateurs*/
    void clearAccumulateurs();

    /*definit la matrice d'inertie inverse comme etant celle d'une sphere avec les formules d�fini*/
    void setInverseInertieTensorSphere(float p_masse, float p_rayon);

    /*definit la matrice d'inertie inverse comme etant celle d'un parallelepipede rectangle avec les
     * formules d�fini*/
    void setInverseInertieTensorCube(float p_masse, float p_x, float p_y, float p_z);

    /*actiualise la matrice transforme*/
    void calculDonneesDerivees();

    void integrate(float p_duration);

    /*applique un force p_force en un poin p_point du rigidbody avec p_point et p_force dans le
     * repere monde*/
    void addForceAtPoint(Vecteur3D p_force, Vecteur3D p_point);

    /*applique un force p_force en un poin p_point du rigidbody avec  p_force dans le repere monde
     * et p_point dans le repere objet*/
    void addForceAtBodyPoint(Vecteur3D p_force, Vecteur3D p_point);
};