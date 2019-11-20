#include "Quaternion.hpp"

void Quaternion::setData(std::vector<float> p_vector) { m_data = p_vector; }

void Quaternion::setValueAt(float p_value, int p_index) { m_data.at(p_index) = p_value; }

// normalize
void Quaternion::normalize()
{
    float l_r = m_data.at(0);
    float l_i = m_data.at(1);
    float l_j = m_data.at(2);
    float l_k = m_data.at(3);

    float l_d = l_r * l_r + l_i * l_i + l_j * l_j + l_k * l_k;

    if (l_d == 0)
    {
        l_r = 1;
        m_data.at(0) = l_r;
        m_data.at(1) = l_i;
        m_data.at(2) = l_j;
        m_data.at(3) = l_k;
    }
    else
    {
        l_d = 1 / sqrt(l_d);
        m_data.at(0) = l_d * l_r;
        m_data.at(1) = l_d * l_i;
        m_data.at(2) = l_d * l_j;
        m_data.at(3) = l_d * l_k;
    }
}

// q1q2
Quaternion& Quaternion::operator*=(const Quaternion& p_quaternion)
{
    // float l_w1 = m_data.at(0);
    // float l_x1 = m_data.at(1);
    // float l_y1 = m_data.at(2);
    // float l_z1 = m_data.at(3);

    // float l_w2 = p_quaternion.m_data.at(0);
    // float l_x2 = p_quaternion.m_data.at(1);
    // float l_y2 = p_quaternion.m_data.at(2);
    // float l_z2 = p_quaternion.m_data.at(3);

    float l_w1 = p_quaternion.m_data.at(0);
    float l_x1 = p_quaternion.m_data.at(1);
    float l_y1 = p_quaternion.m_data.at(2);
    float l_z1 = p_quaternion.m_data.at(3);

    float l_w2 = m_data.at(0);
    float l_x2 = m_data.at(1);
    float l_y2 = m_data.at(2);
    float l_z2 = m_data.at(3);

    float l_w = l_w1 * l_w2 - l_x1 * l_x2 - l_y1 * l_y2 - l_z1 * l_z2;
    float l_x = l_w1 * l_x2 + l_w2 * l_x1 + l_y1 * l_z2 - l_z1 * l_y2;
    float l_y = l_w1 * l_y2 + l_w2 * l_y1 + l_z1 * l_x2 - l_x1 * l_z2;
    float l_z = l_w1 * l_z2 + l_w2 * l_z1 + l_x1 * l_y2 - l_y1 * l_x2;

    m_data.at(0) = l_w;
    m_data.at(1) = l_x;
    m_data.at(2) = l_y;
    m_data.at(3) = l_z;
    return *this;
}

Quaternion Quaternion::operator*(const Quaternion& p_quaternion)
{
    std::vector<float> vector_for_quater;
    vector_for_quater.push_back(0);
    vector_for_quater.push_back(0);
    vector_for_quater.push_back(0);
    vector_for_quater.push_back(0);

    Quaternion l_result(vector_for_quater);
    float l_w1 = p_quaternion.m_data.at(0);
    float l_x1 = p_quaternion.m_data.at(1);
    float l_y1 = p_quaternion.m_data.at(2);
    float l_z1 = p_quaternion.m_data.at(3);

    float l_w2 = m_data.at(0);
    float l_x2 = m_data.at(1);
    float l_y2 = m_data.at(2);
    float l_z2 = m_data.at(3);

    float l_w = l_w1 * l_w2 - l_x1 * l_x2 - l_y1 * l_y2 - l_z1 * l_z2;
    float l_x = l_w1 * l_x2 + l_w2 * l_x1 + l_y1 * l_z2 - l_z1 * l_y2;
    float l_y = l_w1 * l_y2 + l_w2 * l_y1 + l_z1 * l_x2 - l_x1 * l_z2;
    float l_z = l_w1 * l_z2 + l_w2 * l_z1 + l_x1 * l_y2 - l_y1 * l_x2;

    l_result.m_data.at(0) = l_w;
    l_result.m_data.at(1) = l_x;
    l_result.m_data.at(2) = l_y;
    l_result.m_data.at(3) = l_z;

    return l_result;
}

Quaternion& Quaternion::operator*=(const float p_float)
{

    m_data.at(0) *= p_float;
    m_data.at(1) *= p_float;
    m_data.at(2) *= p_float;
    m_data.at(3) *= p_float;

    return *this;
}
Quaternion Quaternion::operator*(const float p_float)
{

    std::vector<float> vector_for_quater;
    vector_for_quater.push_back(0);
    vector_for_quater.push_back(0);
    vector_for_quater.push_back(0);
    vector_for_quater.push_back(0);

    Quaternion l_result(vector_for_quater);
    l_result.m_data.at(0) = m_data.at(0) * p_float;
    l_result.m_data.at(1) = m_data.at(1) * p_float;
    l_result.m_data.at(2) = m_data.at(2) * p_float;
    l_result.m_data.at(3) = m_data.at(3) * p_float;
    return l_result;
}

Quaternion& Quaternion::operator+=(const Quaternion& p_quaternion)
{
    m_data.at(0) += p_quaternion.m_data.at(0);
    m_data.at(1) += p_quaternion.m_data.at(1);
    m_data.at(2) += p_quaternion.m_data.at(2);
    m_data.at(3) += p_quaternion.m_data.at(3);
    return *this;
}

Quaternion Quaternion::operator+(const Quaternion& p_quaternion)
{
    std::vector<float> vector_for_quater;
    vector_for_quater.push_back(0);
    vector_for_quater.push_back(0);
    vector_for_quater.push_back(0);
    vector_for_quater.push_back(0);

    Quaternion l_result(vector_for_quater);
    l_result.m_data.at(0) = m_data.at(0) + p_quaternion.m_data.at(0);
    l_result.m_data.at(1) = m_data.at(1) + p_quaternion.m_data.at(1);
    l_result.m_data.at(2) = m_data.at(2) + p_quaternion.m_data.at(2);
    l_result.m_data.at(3) = m_data.at(3) + p_quaternion.m_data.at(3);

    return l_result;
}

// rotatebyVector
void Quaternion::faireRotation(Vecteur3D& p_vecteur)
{
    std::vector<float> l_vector;

    // std::cout << "p_vetcuer.getX()..." << std::endl;

    // std::cout << std::to_string(p_vecteur.getX()) << std::endl;
    // std::cout << std::to_string(p_vecteur.getY()) << std::endl;
    // std::cout << std::to_string(p_vecteur.getZ()) << std::endl;

    l_vector.push_back(0);
    l_vector.push_back(p_vecteur.getX());
    l_vector.push_back(p_vecteur.getY());
    l_vector.push_back(p_vecteur.getZ());

    // std::cout << "l_vetcuer.getX()..." << std::endl;

    // std::cout << std::to_string(l_vector.at(0)) << std::endl;
    // std::cout << std::to_string(l_vector.at(1)) << std::endl;
    // std::cout << std::to_string(l_vector.at(2)) << std::endl;
    // std::cout << std::to_string(l_vector.at(3)) << std::endl;

    Quaternion q = Quaternion(l_vector);

    // std::cout << "Banane" << std::endl;

    // std::cout << q.getAt(0) << std::endl;
    // std::cout << q.getAt(1) << std::endl;
    // std::cout << q.getAt(2) << std::endl;
    // std::cout << q.getAt(3) << std::endl;

    // faire self . q
    *this *= q;
    ;
}

// UpdateAngularVelocity
void Quaternion::updateAngularVelocity(Vecteur3D& p_vecteur, float p_temps)
{

    // l_vector est le vector qui permet de créer le quaternion de rotation l_w
    std::vector<float> l_vector;

    l_vector.push_back(0);
    l_vector.push_back(p_vecteur.getX());
    l_vector.push_back(p_vecteur.getY());
    l_vector.push_back(p_vecteur.getZ());

    Quaternion l_w = Quaternion(l_vector);

    //std::cout << "quaternion l_w" << std::endl;

    //std::cout << std::to_string(l_w.getAt(0)) << std::endl;
    //std::cout << std::to_string(l_w.getAt(1)) << std::endl;
    //std::cout << std::to_string(l_w.getAt(2)) << std::endl;
    //std::cout << std::to_string(l_w.getAt(3)) << std::endl;

    Quaternion l_produit;
    l_produit = *this * l_w;

    //std::cout << "quaternion l_produit" << std::endl;

    //std::cout << std::to_string(l_produit.getAt(0)) << std::endl;
    //std::cout << std::to_string(l_produit.getAt(1)) << std::endl;
    //std::cout << std::to_string(l_produit.getAt(2)) << std::endl;
    //std::cout << std::to_string(l_produit.getAt(3)) << std::endl;

    *this = *this + (l_produit * (p_temps / 2));
}

std::string Quaternion::print()
{
    std::string str("");
    if (!m_data.empty())
    {
        for (int i = 0; i < 4; i++)
        {
            str += std::to_string(m_data[i]);
            str += " ";
        }
    }
    return str;
}
