#pragma once
#include <cmath>
#include <iostream>

/*
 Cette classe represente un vecteur contenant 3 coordonnees
*/
class Vecteur3D
{
private:
    float m_x = 0; // Coordonnee sur l'axe X
    float m_y = 0; // Coordonnee sur l'axe Y
    float m_z = 0; // Coordonnee sur l'axe Z

public:
	// Constructeurs & Destructeur
    Vecteur3D() = default;
    Vecteur3D(float p_x, float p_y, float p_z) : m_x(p_x), m_y(p_y), m_z(p_z) {};
    Vecteur3D(const Vecteur3D& p_vecteur) : m_x(p_vecteur.m_x), m_y(p_vecteur.m_x), m_z(p_vecteur.m_z) {};
    ~Vecteur3D() = default;

    // Getters
    const float getX() const { return m_x; }
    const float getY() const { return m_y; }
    const float getZ() const { return m_z; }

    // Setters
    void setX(const float p_x) { m_x = p_x; }
    void setY(const float p_y) { m_y = p_y; }
    void setZ(const float p_z) { m_z = p_z; }

    Vecteur3D operator+(const Vecteur3D& p_vecteur);			// Operation d'addition
    Vecteur3D& operator+=(const Vecteur3D& p_vecteur);			// Operation d'addition sur le vecteur courant
    Vecteur3D operator^(const Vecteur3D& p_vecteur);			// Operation produit vectoriel
    Vecteur3D& operator^=(const Vecteur3D& p_vecteur);			// Operation produit vectoriel sur le vecteur courant
    Vecteur3D operator*(float const p_nombre);					// Operation multiplication avec scalaire
    Vecteur3D& operator*=(float const p_nombre);				// Operation multiplication avec scalaire sur le vecteur courant
    Vecteur3D operator-(const Vecteur3D& p_vecteur);			// Operation soustraction
    Vecteur3D& operator-=(const Vecteur3D& p_vecteur);			// Operation soustraction sur le vecteur courant
    Vecteur3D produitComposante(const Vecteur3D& p_vecteur);	// Operation produit composante
    float produitScalaire(Vecteur3D& p_vecteur);                // Operation produit scalaire
    float norme();												// Operation norme
    float normeCarre();											// Operation norme
    Vecteur3D normalise();										// Retourne le vecteur normalise

    friend std::ostream& operator<<(std::ostream& p_out, const Vecteur3D& p_vecteur); // Affichage par le flux
};
