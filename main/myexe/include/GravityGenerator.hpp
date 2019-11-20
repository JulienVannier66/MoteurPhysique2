#pragma once
#include "RigidBody.hpp"
#include "Vecteur3D.hpp"

/*Classe servant à générer la force de gravité*/

class GravityGenerator
{
private:
    Vecteur3D gravity = Vecteur3D(0, -9.81, 0); // Vecteur gravite

public:
    // Constructeurs & Destructeur
    GravityGenerator() {}
    GravityGenerator(Vecteur3D gravity) { this->gravity = gravity; }
    GravityGenerator(const GravityGenerator& gravityGenerator) : gravity(gravityGenerator.gravity){};
    ~GravityGenerator() {}

    // Getters
    Vecteur3D getGravity() { return gravity; }

    // Setters
    void setGravity(Vecteur3D gravity) { this->gravity = gravity; }

    void updateForce(RigidBody p_rigidbody,float duration); // Ajoute la force a la particule renseignee
};