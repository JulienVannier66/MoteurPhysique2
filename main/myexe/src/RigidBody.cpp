#pragma once
#include <RigidBody.hpp>

void RigidBody::addForce(Vecteur3D p_force) { m_forceAccum += p_force; }

void RigidBody::addTorque(Vecteur3D p_torque) { m_torqueAccum += p_torque; }

void RigidBody::clearAccumulateurs()
{
    m_forceAccum.setX(0);
    m_forceAccum.setY(0);
    m_forceAccum.setZ(0);
    m_torqueAccum.setX(0);
    m_torqueAccum.setY(0);
    m_torqueAccum.setZ(0);
}

void RigidBody::calculDonneesDerivees()
{
    m_transforme = Matrix4::setOrientation(m_orientation, m_position);
}

void RigidBody::integrate(float p_duration)
{
    Vecteur3D l_linearAcceleration = m_forceAccum * m_inverseMass;							// Calcul de l'acceleration lineaire
    Vecteur3D l_angularAcceleration = m_torqueAccum * m_inverseInertiatensor;				// Calcul de l'acceleration angulaire
    m_velocite = m_velocite * pow(m_linearDumping, p_duration) + l_linearAcceleration;		// Update velocite lineaire
    m_rotation = m_rotation * pow(m_angularDumping, p_duration) + l_angularAcceleration;	// Update velocite angulaire

	m_position += m_velocite * p_duration;													// Update position
    m_orientation.faireRotation(m_rotation * p_duration);									// Update orientation
    calculDonneesDerivees();																// Calcul des donnees derivees
    clearAccumulateurs();																	// Vidage des accumulateurs
}

void RigidBody::setInverseInertieTensorCube(float p_masse, float p_rayon)
{
    /*on applique la formule connu pour un tenseur de sphere*/
    m_inverseInertiatensor = Matrix3();
    m_inverseInertiatensor *= (2 / 5 * p_masse * p_rayon * p_rayon);
    m_inverseInertiatensor.inverse();
}

void RigidBody::setInverseInertieTensorCube(float p_masse, float p_x, float p_y, float p_z)
{
    /*on applique la formule connu pour un tenseur de parallelepipede rectangle*/
    m_inverseInertiatensor.setMatrixAt(0, 1 / 12 * p_masse * (p_y * p_y + p_z * p_z));
    m_inverseInertiatensor.setMatrixAt(4, 1 / 12 * p_masse * (p_x * p_x + p_z * p_z));
    m_inverseInertiatensor.setMatrixAt(8, 1 / 12 * p_masse * (p_y * p_y + p_x * p_x));
    m_inverseInertiatensor.inverse();
}

void RigidBody::addForceAtPoint(Vecteur3D p_force, Vecteur3D p_point)
{
    p_point.worldToLocal(m_transforme);

    addForce(p_force);
    addTorque(p_point ^ p_force);
}

void RigidBody::addForceAtBodyPoint(Vecteur3D p_force, Vecteur3D p_point)
{
    p_point.localToWorld(m_transforme);
    addForceAtPoint(p_force, p_point);
}