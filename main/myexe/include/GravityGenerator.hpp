#pragma once
#include "Particule.h"
#include "ParticuleForceGenerator.h"
#include "Vecteur3D.h"

class GravityForceGenerator
{
private:
    Vecteur3D gravity = Vecteur3D(0, -9.81, 0); // Vecteur gravite
    int count = 0;

public:
    // Constructeurs & Destructeur
    GravityForceGenerator() {}
    GravityForceGenerator(Vecteur3D gravity) { this->gravity = gravity; }
    GravityForceGenerator(const GravityForceGenerator& gravityForceGenerator)
        : gravity(gravityForceGenerator.gravity){};
    ~GravityForceGenerator() {}

    // Getters
    Vecteur3D getGravity() { return gravity; }

    // Setters
    void setGravity(Vecteur3D gravity) { this->gravity = gravity; }

    void updateForce(Particule* particule,
                     float duration); // Ajoute la force a la particule renseignee
};