#pragma once
#include "Quaternion.h"
#include "Vecteur3D.h"
#include <iostream>
#include <vector>

class Matrix4
{
private:
    std::vector<float> m_data;

public:
    // Constructors

    // Constructeur par defaut
    Matrix4(){};

    // Constructeur via un tableau
    Matrix4(std::vector<float> p_data) { m_data = p_data; };

    // Constructeur de copie
    Matrix4(Matrix4& p_matrix4) { m_data = p_matrix4.getAll(); };

    // Destructor
    ~Matrix4(){};

    // Getteurs
    std::vector<float> getAll();
    float get(int p_i);

    // Setteurs
    void setMatrix4(Matrix4& p_matrix4);
    void setValueAt(float p_value, int p_index);

    // Produit avec un vecteur
    Vecteur3D operator*(const Vecteur3D p_vector);

    // Surcharge operateur
    Matrix4 operator*(const Matrix4 p_matrix4);

    // Renvoie la matrice inverse
    Matrix4 getInverse();

    // Transforme un quaternion en matrice
    Matrix4 setOrientation(Quaternion p_quaternion);

    // Ajouter  transformation et transformation inverse pour vecteurs directions (dans Matrix4)
    // Tourne l'objet d'orientation p_quaternion, et donc modifie p_quaternion
    void transformation(Quaternion p_quaternion);
    // transformation inverse
    void transformationInverse(Quaternion p_quaternion);
};