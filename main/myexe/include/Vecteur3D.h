#pragma once
#include <cmath>
#include <iostream>

/*
 Cette classe represente un vecteur contenant 3 coordonnees
*/
class Vecteur3D
{
private:
	float x = 0; // Coordonnee sur l'axe X
	float y = 0; // Coordonnee sur l'axe Y
	float z = 0; // Coordonnee sur l'axe Z

public:
	// Constructeurs & Destructeur
	Vecteur3D() {};
	Vecteur3D(float x, float y, float z) : x(x), y(y), z(z) {};
	Vecteur3D(const Vecteur3D& vecteur) : x(vecteur.x), y(vecteur.y), z(vecteur.z) {};
	~Vecteur3D() {};

	// Getters
	const float getX() const { return x; }
	const float getY() const { return y; }
	const float getZ() const { return z; }

	// Setters
	void setX(const float x) { this->x = x; }
	void setY(const float y) { this->y = y; }
	void setZ(const float z) { this->z = z; }

	Vecteur3D operator+(const Vecteur3D& vecteur);			// Operation d'addition
	Vecteur3D& operator+=(const Vecteur3D& vecteur);		// Operation d'addition sur le vecteur courant
	Vecteur3D operator^(const Vecteur3D& vecteur);			// Operation produit vectoriel
	Vecteur3D& operator^=(const Vecteur3D& vecteur);		// Operation produit vectoriel sur le vecteur courant
	Vecteur3D operator*(float const nombre);				// Operation multiplication avec scalaire
	Vecteur3D& operator*=(float const nombre);				// Operation multiplication avec scalaire sur le vecteur courant
	Vecteur3D operator-(const Vecteur3D& vecteur);			// Operation soustraction
	Vecteur3D& operator-=(const Vecteur3D& vecteur);		// Operation soustraction sur le vecteur courant
	Vecteur3D produitComposante(const Vecteur3D& vecteur);	// Operation produit composante
	float produitScalaire(Vecteur3D& vecteur);				// Operation produit scalaire
	float norme();											// Operation norme
	float normeCarre();										// Operation norme
	Vecteur3D normalise();									// Retourne le vecteur normalise

	friend std::ostream& operator<<(std::ostream& out, const Vecteur3D& vecteur); // Affichage par le flux

	void testVecteur3D();									// Fonction de test de la classe
};