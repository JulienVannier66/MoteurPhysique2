#pragma once
#include "Vecteur3D.hpp"
#include <vector>

class Quaternion
{
private:
    std::vector<float> m_data;

public:
    // Constructors

    // Default
    Quaternion(){};

    // Via vector
    Quaternion(std::vector<float> p_vector) { m_data = p_vector; }
    // Copie
    Quaternion(Quaternion& p_quaternion) { m_data = p_quaternion.m_data; };

    // Destructor
    ~Quaternion(){};

    // Getteurs
    std::vector<float> getData() { return m_data; };
    float getAt(int p_index) { return m_data.at(p_index); };

    // Setteurs
    void setData(std::vector<float> p_vector);
    void setValueAt(float p_value, int p_index);

    // normalize
    void normalize();

    // q1q2
    Quaternion& operator*=(const Quaternion& p_quaternion);
    Quaternion operator*(const Quaternion& p_quaternion);

	Quaternion& operator*=(float const p_float);
    Quaternion operator*(float const p_float);

    Quaternion& operator+=(const Quaternion& p_quaternion);
    Quaternion operator+(const Quaternion& p_quaternion);

    // rotatebyVector
    void faireRotation(Vecteur3D& p_vecteur);

    // UpdateAngularVelocity
    void updateAngularVelocity(Vecteur3D& p_vecteur, float p_temps);

	//Fonction print pour les tests
    std::string print();
};