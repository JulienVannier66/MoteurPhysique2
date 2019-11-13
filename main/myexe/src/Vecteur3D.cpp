#include "Vecteur3D.hpp"

Vecteur3D Vecteur3D::operator+(const Vecteur3D& p_vecteur)
{
    Vecteur3D l_result;
    l_result.m_x = m_x + p_vecteur.m_x;
    l_result.m_y = m_y + p_vecteur.m_y;
    l_result.m_z = m_z + p_vecteur.m_z;
    return l_result;
}

Vecteur3D& Vecteur3D::operator+=(const Vecteur3D& p_vecteur)
{
    m_x += p_vecteur.m_x;
    m_x += p_vecteur.m_x;
    m_x += p_vecteur.m_x;
    return *this;
}

Vecteur3D Vecteur3D::operator-(const Vecteur3D& p_vecteur)
{
    Vecteur3D l_result;
    l_result.m_x = m_x - p_vecteur.m_x;
    l_result.m_y = m_y - p_vecteur.m_y;
    l_result.m_z = m_z - p_vecteur.m_z;
    return l_result;
}

Vecteur3D& Vecteur3D::operator-=(const Vecteur3D& p_vecteur)
{
    m_x -= p_vecteur.m_x;
    m_y -= p_vecteur.m_y;
    m_z -= p_vecteur.m_z;
    return *this;
}

Vecteur3D Vecteur3D::operator*(float const p_nombre)
{
    Vecteur3D l_result;
    l_result.m_x = m_x * p_nombre;
    l_result.m_y = m_y * p_nombre;
    l_result.m_z = m_z * p_nombre;
    return l_result;
}

Vecteur3D& Vecteur3D::operator*=(float const p_nombre)
{
    m_x *= p_nombre;
    m_y *= p_nombre;
    m_z *= p_nombre;
    return *this;
}

Vecteur3D Vecteur3D::operator^(const Vecteur3D& p_vecteur)
{
    Vecteur3D l_result;
    l_result.m_x = m_y * p_vecteur.m_z - m_z * p_vecteur.m_y;
    l_result.m_y = m_z * p_vecteur.m_x - m_x * p_vecteur.m_z;
    l_result.m_z = m_x * p_vecteur.m_y - m_y * p_vecteur.m_x;
    return l_result;
}

Vecteur3D& Vecteur3D::operator^=(const Vecteur3D& p_vecteur)
{
    float l_x = m_x;
    float l_y = m_y;
    float l_z = m_z;
    m_x = l_y * p_vecteur.m_z - l_z * p_vecteur.m_y;
    m_y = l_z * p_vecteur.m_x - l_x * p_vecteur.m_z;
    m_z = l_x * p_vecteur.m_y - l_y * p_vecteur.m_x;
    return *this;
}

Vecteur3D Vecteur3D::produitComposante(const Vecteur3D& p_vecteur)
{
    Vecteur3D l_result;
    l_result.m_x = m_x * p_vecteur.m_x;
    l_result.m_y = m_y * p_vecteur.m_y;
    l_result.m_z = m_z * p_vecteur.m_z;
    return l_result;
}


float Vecteur3D::produitScalaire(Vecteur3D& p_vecteur)
{
    return m_x * p_vecteur.m_x + m_y * p_vecteur.m_y + m_z * p_vecteur.m_z;
}


float Vecteur3D::norme()
{
	return sqrt(produitScalaire(*this));
}

float Vecteur3D::normeCarre()
{
	return pow(norme(), 2);
}

std::ostream& operator<<(std::ostream& p_out, const Vecteur3D& p_vecteur)
{
    return p_out << "[" << p_vecteur.m_x << ";" << p_vecteur.m_y << ";" << p_vecteur.m_z << "]";
}

Vecteur3D Vecteur3D::normalise()
{
    float l_longueur = norme();
    return (l_longueur == 0) ? Vecteur3D(0, 0, 0)
                             : Vecteur3D(m_x / l_longueur, m_y / l_longueur, m_z / l_longueur);
}

std::string Vecteur3D::print() {
    std::string result("[" + std::to_string(m_x) + ";" + std::to_string(m_y) + ";" + std::to_string(m_z) + "]");
    return result;
}