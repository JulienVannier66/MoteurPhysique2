#include "Vecteur3D.h"

Vecteur3D Vecteur3D::operator+(const Vecteur3D& vecteur)
{
	Vecteur3D result;
	result.x = x + vecteur.x;
	result.y = y + vecteur.y;
	result.z = z + vecteur.z;
	return result;
}

Vecteur3D& Vecteur3D::operator+=(const Vecteur3D& vecteur)
{
	x += vecteur.x;
	y += vecteur.y;
	z += vecteur.z;
	return *this;
}

Vecteur3D Vecteur3D::operator-(const Vecteur3D& vecteur)
{
	Vecteur3D result;
	result.x = x - vecteur.x;
	result.y = y - vecteur.y;
	result.z = z - vecteur.z;
	return result;
}

Vecteur3D& Vecteur3D::operator-=(const Vecteur3D& vecteur)
{
	x -= vecteur.x;
	y -= vecteur.y;
	z -= vecteur.z;
	return *this;
}

Vecteur3D Vecteur3D::operator*(float const nombre)
{
	Vecteur3D result;
	result.x = x * nombre;
	result.y = y * nombre;
	result.z = z * nombre;
	return result;
}

Vecteur3D& Vecteur3D::operator*=(float const nombre)
{
	x *= nombre;
	y *= nombre;
	z *= nombre;
	return *this;
}

Vecteur3D Vecteur3D::operator^(const Vecteur3D& vecteur)
{
	Vecteur3D result;
	result.x = y * vecteur.getZ() - z * vecteur.getY();
	result.y = z * vecteur.getX() - x * vecteur.getZ();
	result.z = x * vecteur.getY() - y * vecteur.getX();
	return result;
}

Vecteur3D& Vecteur3D::operator^=(const Vecteur3D& vecteur)
{
	float x1 = x;
	float y1 = y;
	float z1 = z;
	x = y1 * vecteur.getZ() - z1 * vecteur.getY();
	y = z1 * vecteur.getX() - x1 * vecteur.getZ();
	z = x1 * vecteur.getY() - y1 * vecteur.getX();
	return *this;
}

Vecteur3D Vecteur3D::produitComposante(const Vecteur3D& vecteur)
{
	Vecteur3D result;
	result.x = x * vecteur.getX();
	result.y = y * vecteur.getY();
	result.z = z * vecteur.getZ();
	return result;
}


float Vecteur3D::produitScalaire(Vecteur3D& vecteur)
{
	return x * vecteur.getX() + y * vecteur.getY() + z * vecteur.getZ();
}


float Vecteur3D::norme()
{
	return sqrt(produitScalaire(*this));
}

float Vecteur3D::normeCarre()
{
	return pow(norme(), 2);
}

std::ostream& operator<<(std::ostream& out, const Vecteur3D& vecteur)
{
	return out << "[" << vecteur.getX() << ";" << vecteur.getY() << ";" << vecteur.getZ() << "]";
}

Vecteur3D Vecteur3D::normalise()
{
	float longueur = norme();
	return (longueur == 0) ? Vecteur3D(0, 0, 0) : Vecteur3D(x / longueur, y / longueur, z / longueur);
}

void Vecteur3D::testVecteur3D()
{
	std::cout << "Hello World!\n";
	Vecteur3D v(2, 6, 7);
	Vecteur3D v2(4, -6, 3);
	Vecteur3D v3;

	std::cout << v << "\n";
	std::cout << v2 << "\n";
	std::cout << v3 << "\n";

	v3 = v + v2;
	std::cout << v3 << "\n";

	v3 = v - v2;
	std::cout << v3 << "\n";

	v3 = v * 2;
	std::cout << v3 << "\n";

	v3 = v ^ v2;
	std::cout << v3 << "\n";

	std::cout << v.produitScalaire(v2) << "\n";
	std::cout << v.norme() << "\n";
	std::cout << v2.norme() << "\n";
}