#pragma once
#include <Quaternion.hpp>
#include <Vecteur3D.hpp>
#include <iostream>
#include <vector>

//Classe decrivant les matrices 3x4
class Matrix4
{
private:
	//On stockera les 12 floats dans u std::vector
    std::vector<float> m_data;

public:
    // Constructors

    // Constructeur par defaut
    Matrix4()
	{
        m_data.push_back(0);
        m_data.push_back(0);
        m_data.push_back(0);
        m_data.push_back(0);
        m_data.push_back(0);
        m_data.push_back(0);
        m_data.push_back(0);
        m_data.push_back(0);
        m_data.push_back(0);
        m_data.push_back(0);
        m_data.push_back(0);
        m_data.push_back(0);
	}

    // Constructeur via un ensemble de float
    Matrix4(float a, float b, float c, float d, float e, float f, float g, float h, float i,
            float j, float k, float l)
    {
		//std::vector.push_back(x) ajoute x a la fin du vecteur 
        m_data.push_back(a);
        m_data.push_back(b);
        m_data.push_back(c);
        m_data.push_back(d);
        m_data.push_back(e);
        m_data.push_back(f);
        m_data.push_back(g);
        m_data.push_back(h);
        m_data.push_back(i);
        m_data.push_back(j);
        m_data.push_back(k);
        m_data.push_back(l);
    }

    // Constructeur via un std::vector
    Matrix4(std::vector<float> p_data) { m_data = p_data; };

    // Constructeur de copie (a partir d'une autre matrice 3x4)
    Matrix4(Matrix4& p_matrix4) { m_data = p_matrix4.getAll(); };

    // Destructor
    ~Matrix4(){};

    // Getteurs

	//Recupere l'ensemble des elements de la matrice sous forme de std::vector
    std::vector<float> getAll();

	//Recupere l'element de la matrice d'index p_i
    float get(int p_i);

    // Setteurs

	//Modifie l'ensemble de la matrice
    void setMatrix4(Matrix4& p_matrix4);

	//Modifie la valeur d'index p_index par la valeur p_value
    void setValueAt(float p_value, int p_index);

	//Surcharge d'operateur d'egalite
    Matrix4& operator=(Matrix4 const& p_mat)
    {
        if (p_mat.m_data.size() == 12)
        {
            m_data[0] = p_mat.m_data[0];
            m_data[1] = p_mat.m_data[1];
            m_data[2] = p_mat.m_data[2];
            m_data[3] = p_mat.m_data[3];
            m_data[4] = p_mat.m_data[4];
            m_data[5] = p_mat.m_data[5];
            m_data[6] = p_mat.m_data[6];
            m_data[7] = p_mat.m_data[7];
            m_data[8] = p_mat.m_data[8];
            m_data[9] = p_mat.m_data[9];
            m_data[10] = p_mat.m_data[10];
            m_data[11] = p_mat.m_data[11];
        }
        else
            std::cout << "la matrice passé en argument au constructeur n'est pas valide (elle n'a "
                         "pas 12 elements)"
                      << std::endl;

        return *this;
    }

    // Produit avec un vecteur
    Vecteur3D operator*(const Vecteur3D p_vector);

    // Surcharge operateur (matrice * matrice)
    Matrix4 operator*(const Matrix4 p_matrix4);
	
	//Surcharge operateur (matrice * float)
    Matrix4 operator*(const float p_float)
    {

        Matrix4 result(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        if (m_data.size() == 12)
        {
            result.m_data[0] = p_float * m_data[0];
            result.m_data[1] = p_float * m_data[1];
            result.m_data[2] = p_float * m_data[2];
            result.m_data[3] = p_float * m_data[3];
            result.m_data[4] = p_float * m_data[4];
            result.m_data[5] = p_float * m_data[5];
            result.m_data[6] = p_float * m_data[6];
            result.m_data[7] = p_float * m_data[7];
            result.m_data[8] = p_float * m_data[8];
            result.m_data[9] = p_float * m_data[9];
            result.m_data[10] = p_float * m_data[10];
            result.m_data[11] = p_float * m_data[11];
        }
        else
            std::cout << "la matrice passé en argument au constructeur n'est pas valide (elle n'a "
                         "pas 12 elements)"
                      << std::endl;

        return result;
    }

    // Renvoie la matrice inverse
    Matrix4 getInverse();

    // Transforme un quaternion en matrice
    static Matrix4 setOrientation(Quaternion p_quaternion,Vecteur3D p_position);

    // Tourne l'objet d'orientation p_quaternion, et donc modifie p_quaternion
    void transformation(Quaternion p_quaternion);
    // Transformation inverse
    void transformationInverse(Quaternion p_quaternion);

	//Permet d'afficher les elements de la matrice
	//Utilise essentillement pour les tests
    std::string print();
};