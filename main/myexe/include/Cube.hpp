#pragma once
#include <RigidBody.hpp>

class Cube : public RigidBody
{
private:
    float m_demiLongueur[3] = {0.5, 0.5, 0.5};
    BoundingSphere m_boundingSphere;

public:
    Cube()
    {
        RigidBody();
        m_boundingSphere.centre = getPosition();
        m_boundingSphere.rayon =
            sqrt(pow(m_demiLongueur[0], 2) + pow(m_demiLongueur[1], 2) + pow(m_demiLongueur[2], 2))/2;
    }

    Cube(float p_masse, float p_linearDumping, float p_angularDumpling, Vecteur3D p_position,
         Vecteur3D p_velocite, Vecteur3D p_rotation, Quaternion p_orientation, Matrix4 p_transforme,
         Vecteur3D p_centre, float p_demi1, float p_demi2, float p_demi3)
        : RigidBody(p_masse, p_linearDumping, p_angularDumpling, p_position, p_velocite, p_rotation,
                    p_orientation, p_transforme)
    {

        m_demiLongueur[0] = p_demi1;
        m_demiLongueur[1] = p_demi2;
        m_demiLongueur[2] = p_demi3;
        m_boundingSphere.centre = getPosition();
        m_boundingSphere.rayon = sqrt(pow(m_demiLongueur[0], 2) + pow(m_demiLongueur[1], 2) +
                                      pow(m_demiLongueur[2], 2)) /
                                 2;
    }

    Cube(Cube& p_cube)
        : RigidBody(p_cube.getMasse(), p_cube.getLinearDumping(), p_cube.getAngularDumping(),
                    p_cube.getPosition(), p_cube.getVelocite(), p_cube.getRotation(),
                    p_cube.getOrientation(), p_cube.getTransformMatrice())
    {

        m_demiLongueur[0] = p_cube.m_demiLongueur[0];
        m_demiLongueur[1] = p_cube.m_demiLongueur[1];
        m_demiLongueur[2] = p_cube.m_demiLongueur[2];
        m_boundingSphere.centre = getPosition();
        m_boundingSphere.rayon = sqrt(pow(m_demiLongueur[0], 2) + pow(m_demiLongueur[1], 2) +
                                      pow(m_demiLongueur[2], 2)) /
                                 2;
    }

    void setDemiLongueur(float p_demi1, float p_demi2, float p_demi3)
    {
        m_demiLongueur[0] = p_demi1;
        m_demiLongueur[1] = p_demi2;
        m_demiLongueur[2] = p_demi3;
    }

    float* getDemiLongueur() { return m_demiLongueur; }
};