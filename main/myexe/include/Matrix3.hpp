#include <iostream>
#include <vector>
#include <string>
#include <Vecteur3D.hpp>

class Matrix3
{
private:
    std::vector<float> m_matrice;
    /* matrice 3x3 avec les indices suivant:
                    0	1	2
                    3	4	5
                    6	7	8
            */

public:
    // Constructeurs et destructeurs
    /*constructeur par défault, renvoie la matrice identité*/
    Matrix3()
    {
        m_matrice[0] = 1;
        m_matrice[1] = 0;
        m_matrice[2] = 0;
        m_matrice[3] = 0;
        m_matrice[4] = 1;
        m_matrice[5] = 0;
        m_matrice[6] = 0;
        m_matrice[7] = 0;
        m_matrice[8] = 1;
    }

    /*constructeur value*/
    Matrix3(std::vector<float>& p_mat)
    {
        if (p_mat.size() == 9)
        {
            m_matrice[0] = p_mat[0];
            m_matrice[1] = p_mat[1];
            m_matrice[2] = p_mat[2];
            m_matrice[3] = p_mat[3];
            m_matrice[4] = p_mat[4];
            m_matrice[5] = p_mat[5];
            m_matrice[6] = p_mat[6];
            m_matrice[7] = p_mat[7];
            m_matrice[8] = p_mat[8];
        }
        else
            std::cout << "la matrice passé en argument au constructeur n'est pas valide (elle n'a "
                         "pas 9 elements)"
                      << std::endl;
    }

    // getter et setter
    std::vector<float> getMatrix() { return m_matrice; }

    Matrix3& operator=(Matrix3 const& p_mat)
    {
        if (p_mat.m_matrice.size() == 9)
        {
            m_matrice[0] = p_mat.m_matrice[0];
            m_matrice[1] = p_mat.m_matrice[1];
            m_matrice[2] = p_mat.m_matrice[2];
            m_matrice[3] = p_mat.m_matrice[3];
            m_matrice[4] = p_mat.m_matrice[4];
            m_matrice[5] = p_mat.m_matrice[5];
            m_matrice[6] = p_mat.m_matrice[6];
            m_matrice[7] = p_mat.m_matrice[7];
            m_matrice[8] = p_mat.m_matrice[8];
        }
        else
            std::cout << "la matrice passé en argument au constructeur n'est pas valide (elle n'a "
                         "pas 9 elements)"
                      << std::endl;

        return *this;
    }

    /* matrice+matrice */
    Matrix3 operator+(Matrix3 const& p_mat);

    /* matrice+matrice */
    Matrix3& operator+=(Matrix3 const& p_mat);

    /* matrice*matrice */
    Matrix3 operator*(Matrix3 const& p_mat);

    /* matrice*matrice */
    Matrix3& operator*=(Matrix3 const& p_mat);

    /*matrice*float*/
    Matrix3& operator*=(float const& p_number);

    /* matrice*vecteur */
    Vecteur3D operator*(Vecteur3D const& p_vec);

    void transpose();

    static Matrix3 transpose(Matrix3 const p_mat);

    void inverse();

    static Matrix3 inverse(Matrix3 const p_mat);

    float determinant();

	//Matrix3 setOrientation(Quaternion p_quat);

	//std::string print();
};