#pragma once
#include <Matrix3.hpp>

Matrix3 Matrix3::operator+(Matrix3 const& p_mat)
{
    std::vector<float> l_temp_mat;
    for (int i = 0; i < 9; i++) { l_temp_mat.push_back(m_matrice[i] + p_mat.m_matrice[i]); }
    Matrix3 mat(l_temp_mat);
    return mat;
}

Matrix3& Matrix3::operator+=(Matrix3 const& p_mat)
{
    for (int i = 0; i < 9; i++) { m_matrice[i] += p_mat.m_matrice[i]; }
    return *this;
}

Matrix3 Matrix3::operator*(Matrix3 const& p_mat)
{
    std::vector<float> l_temp_mat;
    l_temp_mat.push_back(m_matrice[0] * p_mat.m_matrice[0] + m_matrice[1] * p_mat.m_matrice[3] +
                         m_matrice[2] * p_mat.m_matrice[6]);
    l_temp_mat.push_back(m_matrice[0] * p_mat.m_matrice[1] + m_matrice[1] * p_mat.m_matrice[4] +
                         m_matrice[2] * p_mat.m_matrice[7]);
    l_temp_mat.push_back(m_matrice[0] * p_mat.m_matrice[2] + m_matrice[1] * p_mat.m_matrice[5] +
                         m_matrice[2] * p_mat.m_matrice[8]);
    l_temp_mat.push_back(m_matrice[3] * p_mat.m_matrice[0] + m_matrice[4] * p_mat.m_matrice[3] +
                         m_matrice[5] * p_mat.m_matrice[6]);
    l_temp_mat.push_back(m_matrice[3] * p_mat.m_matrice[1] + m_matrice[4] * p_mat.m_matrice[4] +
                         m_matrice[5] * p_mat.m_matrice[7]);
    l_temp_mat.push_back(m_matrice[3] * p_mat.m_matrice[2] + m_matrice[4] * p_mat.m_matrice[5] +
                         m_matrice[5] * p_mat.m_matrice[8]);
    l_temp_mat.push_back(m_matrice[6] * p_mat.m_matrice[0] + m_matrice[7] * p_mat.m_matrice[3] +
                         m_matrice[8] * p_mat.m_matrice[6]);
    l_temp_mat.push_back(m_matrice[6] * p_mat.m_matrice[1] + m_matrice[7] * p_mat.m_matrice[4] +
                         m_matrice[8] * p_mat.m_matrice[7]);
    l_temp_mat.push_back(m_matrice[6] * p_mat.m_matrice[2] + m_matrice[7] * p_mat.m_matrice[5] +
                         m_matrice[8] * p_mat.m_matrice[8]);
    return Matrix3(l_temp_mat);
}

Matrix3& Matrix3::operator*=(Matrix3 const& p_mat)
{
    std::vector<float> l_temp_mat;
    l_temp_mat.push_back(m_matrice[0] * p_mat.m_matrice[0] + m_matrice[1] * p_mat.m_matrice[3] +
                         m_matrice[2] * p_mat.m_matrice[6]);
    l_temp_mat.push_back(m_matrice[0] * p_mat.m_matrice[1] + m_matrice[1] * p_mat.m_matrice[4] +
                         m_matrice[2] * p_mat.m_matrice[7]);
    l_temp_mat.push_back(m_matrice[0] * p_mat.m_matrice[2] + m_matrice[1] * p_mat.m_matrice[5] +
                         m_matrice[2] * p_mat.m_matrice[8]);
    l_temp_mat.push_back(m_matrice[3] * p_mat.m_matrice[0] + m_matrice[4] * p_mat.m_matrice[3] +
                         m_matrice[5] * p_mat.m_matrice[6]);
    l_temp_mat.push_back(m_matrice[3] * p_mat.m_matrice[1] + m_matrice[4] * p_mat.m_matrice[4] +
                         m_matrice[5] * p_mat.m_matrice[7]);
    l_temp_mat.push_back(m_matrice[3] * p_mat.m_matrice[2] + m_matrice[4] * p_mat.m_matrice[5] +
                         m_matrice[5] * p_mat.m_matrice[8]);
    l_temp_mat.push_back(m_matrice[6] * p_mat.m_matrice[0] + m_matrice[7] * p_mat.m_matrice[3] +
                         m_matrice[8] * p_mat.m_matrice[6]);
    l_temp_mat.push_back(m_matrice[6] * p_mat.m_matrice[1] + m_matrice[7] * p_mat.m_matrice[4] +
                         m_matrice[8] * p_mat.m_matrice[7]);
    l_temp_mat.push_back(m_matrice[6] * p_mat.m_matrice[2] + m_matrice[7] * p_mat.m_matrice[5] +
                         m_matrice[8] * p_mat.m_matrice[8]);
    m_matrice = l_temp_mat;
    return *this;
}

Matrix3& Matrix3::operator*=(float const& p_number)
{
    m_matrice[0] *= p_number;
    m_matrice[1] *= p_number;
    m_matrice[2] *= p_number;
    m_matrice[3] *= p_number;
    m_matrice[4] *= p_number;
    m_matrice[5] *= p_number;
    m_matrice[6] *= p_number;
    m_matrice[7] *= p_number;
    m_matrice[8] *= p_number;
    return *this;
}

Vecteur3D Matrix3::operator*(Vecteur3D const& p_vec)
{
    std::vector<float> l_temp_vec;
    std::cout << "ligne 1 :  " << m_matrice[0] * p_vec.getX() << "  " << m_matrice[1] * p_vec.getY()
              << "  " << m_matrice[2] * p_vec.getZ() << std::endl;
    std::cout << "ligne 2 :  " << m_matrice[3] * p_vec.getX() << "  " << m_matrice[4] * p_vec.getY()
              << "  " << m_matrice[5] * p_vec.getZ() << std::endl;
    std::cout << "ligne 3 :  " << m_matrice[6] * p_vec.getX() << "  " << m_matrice[7] * p_vec.getY()
              << "  " << m_matrice[8] * p_vec.getZ() << std::endl;
    return Vecteur3D(
        m_matrice[0] * p_vec.getX() + m_matrice[1] * p_vec.getY() + m_matrice[2] * p_vec.getZ(),
        m_matrice[3] * p_vec.getX() + m_matrice[4] * p_vec.getY() + m_matrice[5] * p_vec.getZ(),
        m_matrice[6] * p_vec.getX() + m_matrice[7] * p_vec.getY() + m_matrice[8] * p_vec.getZ());
}

void Matrix3::transpose()
{
    float temp1 = m_matrice[1];
    float temp2 = m_matrice[2];
    float temp3 = m_matrice[5];
    m_matrice[1] = m_matrice[3];
    m_matrice[2] = m_matrice[6];
    m_matrice[3] = temp1;
    m_matrice[5] = m_matrice[7];
    m_matrice[6] = temp2;
    m_matrice[7] = temp3;
}

void Matrix3::inverse()
{
    float l_terme0 = m_matrice[4] * m_matrice[8] - m_matrice[5] * m_matrice[7];
    float l_terme1 = m_matrice[2] * m_matrice[7] - m_matrice[1] * m_matrice[8];
    float l_terme2 = m_matrice[1] * m_matrice[5] - m_matrice[2] * m_matrice[4];
    float l_terme3 = m_matrice[5] * m_matrice[6] - m_matrice[3] * m_matrice[8];
    float l_terme4 = m_matrice[0] * m_matrice[8] - m_matrice[2] * m_matrice[6];
    float l_terme5 = m_matrice[2] * m_matrice[3] - m_matrice[0] * m_matrice[5];
    float l_terme6 = m_matrice[3] * m_matrice[7] - m_matrice[4] * m_matrice[6];
    float l_terme7 = m_matrice[1] * m_matrice[6] - m_matrice[0] * m_matrice[7];
    float l_terme8 = m_matrice[0] * m_matrice[4] - m_matrice[1] * m_matrice[3];
    float l_det = determinant();
    if (l_det != 0)
    {
        m_matrice[0] = l_terme0 / l_det;
        m_matrice[1] = l_terme1 / l_det;
        m_matrice[2] = l_terme2 / l_det;
        m_matrice[3] = l_terme3 / l_det;
        m_matrice[4] = l_terme4 / l_det;
        m_matrice[5] = l_terme5 / l_det;
        m_matrice[6] = l_terme6 / l_det;
        m_matrice[7] = l_terme7 / l_det;
        m_matrice[8] = l_terme8 / l_det;
    }
    else
        std::cout << "le determinant est nul, impossible d'inverser la matrice" << std::endl;
}

float Matrix3::determinant()
{
    float l_res =
        m_matrice[0] * m_matrice[4] * m_matrice[8] + m_matrice[3] * m_matrice[7] * m_matrice[2] +
        m_matrice[6] * m_matrice[1] * m_matrice[5] - m_matrice[2] * m_matrice[4] * m_matrice[6] -
        m_matrice[5] * m_matrice[7] * m_matrice[0] - m_matrice[8] * m_matrice[1] * m_matrice[3];
    return l_res;
}

 Matrix3 Matrix3::setOrientation(Quaternion p_quat)
{
    float x = p_quat.getAt(0);
    float y = p_quat.getAt(1);
    float z = p_quat.getAt(2);
    float w = p_quat.getAt(3);

    float l_a = 1 - (2 * y * y + 2 * z * z);
    float l_b = 2 * x * y + 2 * z * w;
    float l_c = 2 * x * z - 2 * y * w;

    float l_e = 2 * x * y - 2 * z * w;
    float l_f = 1 - (2 * x * x + 2 * z * z);
    float l_g = 2 * y * z + 2 * x * w;

    float l_i = 2 * x * z + 2 * y * w;
    float l_j = 2 * y * z - 2 * x * w;
    float l_k = 1 - (2 * x * x + 2 * y * y);

    std::vector<float> myvec{l_a, l_b, l_c, l_e, l_f, l_g, l_i, l_j, l_k};
    return Matrix3(myvec);
}

std::string Matrix3::print()
{
    std::string str("");
    for (int i = 0; i < 9; i++)
    {
        if (m_matrice[i] == 0.00000f)
        {
            str += std::to_string(0.000000);
            str += " ";
        }
        else
        {

            str += std::to_string(m_matrice[i]);
            str += " ";
        }
    }
    return str;
}
