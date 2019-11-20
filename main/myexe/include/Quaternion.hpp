#pragma once

#include "Vecteur3D.hpp"
#include <vector>

// Classe d�crivant la structure des quaternions
class Quaternion
{
private:
    // Pour stocker nos quatres float, on prendra des std::vector. Il faut faire attention �
    // manipuer suelement 4 �l�ments
    std::vector<float> m_data;

public:
    // Constructors

    // Default
    Quaternion(){};

    // Constructeur � partir de 4 floats
    Quaternion(float x, float y, float z, float w)
    {
		//push_back ajoute un �l�ment � la fin d'un std::vector
        m_data.push_back(x);
        m_data.push_back(y);
        m_data.push_back(z);
        m_data.push_back(w);
    }
    // Constructeur � partir d'un vecteur. C'est ici qu'il faut faire attention � bien passer en
    // argument un vecteur de 4 �l�ments. Sinon, le quaternion est rmepli avec 4 z�ros
    Quaternion(std::vector<float> p_vector)
    {
        if (p_vector.size() == 4) { m_data = p_vector; }
        else
        {
            std::vector<float> l_vector;
            l_vector.push_back(0);
            l_vector.push_back(0);
            l_vector.push_back(0);
            l_vector.push_back(0);

        }
    }
    // Constructeur de copie (a partir d'un autre quaternion)
    Quaternion(Quaternion& p_quaternion) { m_data = p_quaternion.m_data; };

    // Destructor
    ~Quaternion(){};

    // Getteurs

	//Retourne le std_vector du quaternion
    std::vector<float> getData() { return m_data; };

	//Retourne l'�l�ment a la position p_index du quaternion 
    float getAt(int p_index) { return m_data.at(p_index); };

    // Setteurs

	//Modifie le std::vector du quaternion
    void setData(std::vector<float> p_vector);

	//Modifie la valeur du std::vector � p_index
    void setValueAt(float p_value, int p_index);

    // Normalise le vecteur
    void normalize();

    // Surcharge d'op�rateurs

	//quaternion * quaternion
    Quaternion& operator*=(const Quaternion& p_quaternion);
    Quaternion operator*(const Quaternion& p_quaternion);

	//quaternion * float
    Quaternion& operator*=(float const p_float);
    Quaternion operator*(float const p_float);

	//quaternion + quaternion
    Quaternion& operator+=(const Quaternion& p_quaternion);
    Quaternion operator+(const Quaternion& p_quaternion);

    //Applique une rotation au quaternion. La rotation est d�crite dans le vecteur3D pass� en argument de la fonction
    void faireRotation(Vecteur3D& p_vecteur);

    // Met a jour la vitesse angulaire (sous forme de quaternion)
    void updateAngularVelocity(Vecteur3D& p_vecteur, float p_temps);

    // Fonction print pour les tests : affiche les �l�ments d'un quaternion
    std::string print();
};