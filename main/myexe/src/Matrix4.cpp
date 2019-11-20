#include "Matrix4.hpp"

void Matrix4::setMatrix4(Matrix4& p_matrix4)
{
    m_data.at(0) = p_matrix4.m_data.at(0);
    m_data.at(1) = p_matrix4.m_data.at(1);
    m_data.at(2) = p_matrix4.m_data.at(2);
    m_data.at(3) = p_matrix4.m_data.at(3);
    m_data.at(4) = p_matrix4.m_data.at(4);
    m_data.at(5) = p_matrix4.m_data.at(5);
    m_data.at(6) = p_matrix4.m_data.at(6);
    m_data.at(7) = p_matrix4.m_data.at(7);
    m_data.at(8) = p_matrix4.m_data.at(8);
    m_data.at(9) = p_matrix4.m_data.at(9);
    m_data.at(10) = p_matrix4.m_data.at(10);
    m_data.at(11) = p_matrix4.m_data.at(11);
}

void Matrix4::setValueAt(float p_value, int p_index) { m_data.at(p_index) = p_value; }

std::vector<float> Matrix4::getAll()
{
    std::vector<float> ret;
    ret = m_data;
    return ret;
}

float Matrix4::get(int p_i)
{
    float ret;
    ret = m_data.at(p_i);
    return ret;
}

Vecteur3D Matrix4::operator*(const Vecteur3D p_vector)
{
    float x = p_vector.getX();
    float y = p_vector.getY();
    float z = p_vector.getZ();

    float l_a = m_data.at(0) * x + m_data.at(1) * y + m_data.at(2) * z + m_data.at(4);
    float l_b = m_data.at(4) * x + m_data.at(5) * y + m_data.at(6) * z + m_data.at(7);
    float l_c = m_data.at(8) * x + m_data.at(9) * y + m_data.at(10) * z + m_data.at(11);

    Vecteur3D ret = Vecteur3D(l_a, l_b, l_c);
    return ret;
}

Matrix4 Matrix4::operator*(const Matrix4 p_matrix4)
{

    float l_a = m_data.at(0) * p_matrix4.m_data.at(0) + m_data.at(1) * p_matrix4.m_data.at(4) +
                m_data.at(2) * p_matrix4.m_data.at(8);
    float l_b = m_data.at(0) * p_matrix4.m_data.at(1) + m_data.at(1) * p_matrix4.m_data.at(5) +
                m_data.at(2) * p_matrix4.m_data.at(9);
    float l_c = m_data.at(0) * p_matrix4.m_data.at(2) + m_data.at(1) * p_matrix4.m_data.at(6) +
                m_data.at(2) * p_matrix4.m_data.at(10);
    float l_d = m_data.at(0) * p_matrix4.m_data.at(3) + m_data.at(1) * p_matrix4.m_data.at(7) +
                m_data.at(2) * p_matrix4.m_data.at(11) + m_data.at(3);

    float l_e = m_data.at(4) * p_matrix4.m_data.at(0) + m_data.at(5) * p_matrix4.m_data.at(4) +
                m_data.at(6) * p_matrix4.m_data.at(8);
    float l_f = m_data.at(4) * p_matrix4.m_data.at(1) + m_data.at(5) * p_matrix4.m_data.at(5) +
                m_data.at(6) * p_matrix4.m_data.at(9);
    float l_g = m_data.at(4) * p_matrix4.m_data.at(2) + m_data.at(5) * p_matrix4.m_data.at(6) +
                m_data.at(6) * p_matrix4.m_data.at(10);
    float l_h = m_data.at(4) * p_matrix4.m_data.at(3) + m_data.at(5) * p_matrix4.m_data.at(7) +
                m_data.at(6) * p_matrix4.m_data.at(11) + m_data.at(7);

    float l_i = m_data.at(8) * p_matrix4.m_data.at(0) + m_data.at(9) * p_matrix4.m_data.at(4) +
                m_data.at(10) * p_matrix4.m_data.at(8);
    float l_j = m_data.at(8) * p_matrix4.m_data.at(1) + m_data.at(9) * p_matrix4.m_data.at(5) +
                m_data.at(10) * p_matrix4.m_data.at(9);
    float l_k = m_data.at(8) * p_matrix4.m_data.at(2) + m_data.at(9) * p_matrix4.m_data.at(6) +
                m_data.at(10) * p_matrix4.m_data.at(10);
    float l_l = m_data.at(8) * p_matrix4.m_data.at(3) + m_data.at(9) * p_matrix4.m_data.at(7) +
                m_data.at(10) * p_matrix4.m_data.at(11) + m_data.at(11);

    Matrix4 ret;
    std::vector<float> myvec{l_a, l_b, l_c, l_d, l_e, l_f, l_g, l_h, l_i, l_j, l_k, l_l};
    ret = Matrix4(myvec);
    return ret;
}

Matrix4 Matrix4::getInverse()
{

    float det =
        m_data.at(8) * m_data.at(5) * m_data.at(2) + m_data.at(4) * m_data.at(9) * m_data.at(2) +
        m_data.at(8) * m_data.at(1) * m_data.at(6) - m_data.at(0) * m_data.at(9) * m_data.at(6) -
        m_data.at(4) * m_data.at(1) * m_data.at(10) - m_data.at(0) * m_data.at(5) * m_data.at(10);

    float l_a = -m_data.at(9) * m_data.at(6) + m_data.at(5) * m_data.at(10);
    l_a = l_a * det;
    float l_b = m_data.at(9) * m_data.at(2) - m_data.at(1) * m_data.at(10);
    l_b = l_b * det;
    float l_c = -m_data.at(5) * m_data.at(2) + m_data.at(1) * m_data.at(6);
    l_c = l_c * det;
    float l_d =
        m_data.at(9) * m_data.at(6) * m_data.at(3) - m_data.at(5) * m_data.at(10) * m_data.at(3) -
        m_data.at(9) * m_data.at(2) * m_data.at(7) + m_data.at(1) * m_data.at(10) * m_data.at(7) +
        m_data.at(5) * m_data.at(2) * m_data.at(11) - m_data.at(1) * m_data.at(6) * m_data.at(11);
    l_d = l_d * det;

    float l_e = m_data.at(8) * m_data.at(6) - m_data.at(4) * m_data.at(10);
    l_e = l_e * det;
    float l_f = -m_data.at(8) * m_data.at(2) + m_data.at(0) * m_data.at(10);
    l_f = l_f * det;
    float l_g = m_data.at(4) * m_data.at(2) - m_data.at(0) * m_data.at(6);
    l_g = l_g * det;
    float l_h =
        -m_data.at(8) * m_data.at(6) * m_data.at(3) + m_data.at(4) * m_data.at(10) * m_data.at(3) +
        m_data.at(8) * m_data.at(2) * m_data.at(7) - m_data.at(0) * m_data.at(10) * m_data.at(7) -
        m_data.at(4) * m_data.at(2) * m_data.at(11) + m_data.at(0) * m_data.at(6) * m_data.at(11);
    l_h = l_h * det;

    float l_i = -m_data.at(8) * m_data.at(5) + m_data.at(4) * m_data.at(9);
    l_i = l_i * det;
    float l_j = m_data.at(8) * m_data.at(1) - m_data.at(0) * m_data.at(9);
    l_j = l_j * det;
    float l_k = -m_data.at(4) * m_data.at(1) + m_data.at(0) * m_data.at(5);
    l_k = l_k * det;
    float l_l =
        m_data.at(8) * m_data.at(5) * m_data.at(3) - m_data.at(4) * m_data.at(9) * m_data.at(3) -
        m_data.at(8) * m_data.at(1) * m_data.at(7) + m_data.at(0) * m_data.at(9) * m_data.at(7) +
        m_data.at(4) * m_data.at(1) * m_data.at(11) - m_data.at(0) * m_data.at(5) * m_data.at(11);
    l_l = l_l * det;

    Matrix4 ret;
    std::vector<float> myvec{l_a, l_b, l_c, l_d, l_e, l_f, l_g, l_h, l_i, l_j, l_k, l_l};
    ret = Matrix4(myvec);
    return ret;
}

Matrix4 Matrix4::setOrientation(Quaternion p_quaternion)
{
    float w = p_quaternion.getAt(0);
    float x = p_quaternion.getAt(1);
    float y = p_quaternion.getAt(2);
    float z = p_quaternion.getAt(3);

    float l_a = 1 - (2 * y * y + 2 * z * z);
    float l_b = 2 * x * y + 2 * z * w;
    float l_c = 2 * x * z - 2 * y * w;
    float l_d = x;

    float l_e = 2 * x * y - 2 * z * w;
    float l_f = 1 - (2 * x * x + 2 * z * z);
    float l_g = 2 * y * z + 2 * x * w;
    float l_h = y;

    float l_i = 2 * x * z + 2 * y * w;
    float l_j = 2 * y * z - 2 * x * w;
    float l_k = 1 - (2 * x * x + 2 * y * y);
    float l_l = z;

    Matrix4 ret;
    std::vector<float> myvec{l_a, l_b, l_c, l_d, l_e, l_f, l_g, l_h, l_i, l_j, l_k, l_l};
    ret = Matrix4(myvec);
    return ret;
}

// Tourne l'objet d'orientation p_quaternion, et donc modifie p_quaternion
void Matrix4::transformation(Quaternion p_quaternion) {

	Matrix4 l_matrice_rotation = setOrientation(p_quaternion);

}
// transformation inverse
void Matrix4::transformationInverse(Quaternion p_quaternion) {

}

std::string Matrix4::print()
{
    std::string str("");
    if (!m_data.empty())
    {
        for (int i = 0; i < 12; i++)
        {
            str += std::to_string(m_data[i]);
            str += " ";
        }
    }
    return str;
}
