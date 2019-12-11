#include "Quaternion.hpp"

void Quaternion::setData(std::vector<float> p_vector) { m_data = p_vector; }

void Quaternion::setValueAt(float p_value, int p_index) { m_data.at(p_index) = p_value; }

void Quaternion::normalize()
{
	//On récupère les valeurs du quaternion pour plus de lisibilité et de meilleurs performances
    float l_r = m_data.at(0);
    float l_i = m_data.at(1);
    float l_j = m_data.at(2);
    float l_k = m_data.at(3);

	//Calcule de d
    float l_d = l_r * l_r + l_i * l_i + l_j * l_j + l_k * l_k;

	//Si d=0, alors r=1 (quaternion sans rotation)
    if (l_d == 0)
    {

        l_r = 1;
        m_data.at(0) = l_r;
        m_data.at(1) = l_i;
        m_data.at(2) = l_j;
        m_data.at(3) = l_k;
    }
	//sinon on divise tout les éléments du quaternion par sqrt(d)
    else
    {
        l_d = 1.0f / sqrt(l_d);
        m_data.at(0) = l_d * l_r;
        m_data.at(1) = l_d * l_i;
        m_data.at(2) = l_d * l_j;
        m_data.at(3) = l_d * l_k;

		//std::cout << "************** -> " << l_d << std::endl;
    }
}

Quaternion& Quaternion::operator*=(const Quaternion& p_quaternion)
{

	//On recupere les valeurs des deux quaternions concernes pour plus de lisibilite et de performance
    float l_w1 = p_quaternion.m_data.at(0);
    float l_x1 = p_quaternion.m_data.at(1);
    float l_y1 = p_quaternion.m_data.at(2);
    float l_z1 = p_quaternion.m_data.at(3);

    float l_w2 = m_data.at(0);
    float l_x2 = m_data.at(1);
    float l_y2 = m_data.at(2);
    float l_z2 = m_data.at(3);

	/*std::cout << "++++ l_w1 : " << l_w1 << std::endl;
	std::cout << "++++ l_x1 : " << l_x1 << std::endl;
	std::cout << "++++ l_y1 : " << l_y1 << std::endl;
	std::cout << "++++ l_z1 : " << l_z1 << std::endl;

	std::cout << "++++ l_w2 : " << l_w2 << std::endl;
    std::cout << "++++ l_x2 : " << l_x2 << std::endl;
    std::cout << "++++ l_y2 : " << l_y2 << std::endl;
    std::cout << "++++ l_z2 : " << l_z2 << std::endl;*/

	//On applique la formule du cours
    float l_w = l_w1 * l_w2 - l_x1 * l_x2 - l_y1 * l_y2 - l_z1 * l_z2;
    float l_x = l_w1 * l_x2 + l_w2 * l_x1 + l_y1 * l_z2 - l_z1 * l_y2;
    float l_y = l_w1 * l_y2 + l_w2 * l_y1 + l_z1 * l_x2 - l_x1 * l_z2;
    float l_z = l_w1 * l_z2 + l_w2 * l_z1 + l_x1 * l_y2 - l_y1 * l_x2;

	/*std::cout << "++++ l_w : " << l_w << std::endl;
    std::cout << "++++ l_x : " << l_x << std::endl;
    std::cout << "++++ l_y : " << l_y << std::endl;
    std::cout << "++++ l_z : " << l_z << std::endl;*/

	//On modifie le quaternion
    m_data.at(0) = l_w;
    m_data.at(1) = l_x;
    m_data.at(2) = l_y;
    m_data.at(3) = l_z;
    return *this;
}

Quaternion Quaternion::operator*(const Quaternion& p_quaternion)
{
	//On cree un std::vector que l'on modifiera par la suite
    std::vector<float> vector_for_quater;
    vector_for_quater.push_back(0);
    vector_for_quater.push_back(0);
    vector_for_quater.push_back(0);
    vector_for_quater.push_back(0);


	//On recupere les valeurs des quaternions concernes
    Quaternion l_result(vector_for_quater);
    float l_w1 = p_quaternion.m_data.at(0);
    float l_x1 = p_quaternion.m_data.at(1);
    float l_y1 = p_quaternion.m_data.at(2);
    float l_z1 = p_quaternion.m_data.at(3);

    float l_w2 = m_data.at(0);
    float l_x2 = m_data.at(1);
    float l_y2 = m_data.at(2);
    float l_z2 = m_data.at(3);


	//On applique la formule du cours
    float l_w = l_w1 * l_w2 - l_x1 * l_x2 - l_y1 * l_y2 - l_z1 * l_z2;
    float l_x = l_w1 * l_x2 + l_w2 * l_x1 + l_y1 * l_z2 - l_z1 * l_y2;
    float l_y = l_w1 * l_y2 + l_w2 * l_y1 + l_z1 * l_x2 - l_x1 * l_z2;
    float l_z = l_w1 * l_z2 + l_w2 * l_z1 + l_x1 * l_y2 - l_y1 * l_x2;

	//On modifie le vecteur resultat
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
	//On cree un vecteur destine a accueillir les donnees de p_vecteur
    std::vector<float> l_vector;

    l_vector.push_back(1);
    l_vector.push_back(p_vecteur.getX());
    l_vector.push_back(p_vecteur.getY());
    l_vector.push_back(p_vecteur.getZ());

	//On cree un quaternion a partir de ce vecteur
    Quaternion q = Quaternion(l_vector);/*
    std::cout << "--------------------" << std::endl;
	std::cout << "q avant norm : " << q.print() << std::endl;*/

    //On applique la rotation (self * q)
    q.normalize();
    //    std::cout << "q apres norm : " << q.print() << std::endl << std::endl;
    //std::cout << "q this avant : " << this->print() << std::endl;
    *this *= q;
    //std::cout << "q this apres sans norm : " << this->print() << std::endl;
    this->normalize();
    //std::cout << "q this apres avec norm: " << this->print() << std::endl;
    //std::cout << "--------------------" << std::endl;
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

	//On cree le quaternion l_w
    Quaternion l_w = Quaternion(l_vector);

	//On applique la formule du cours
    Quaternion l_produit;
    l_produit = *this * l_w;
    *this = *this + (l_produit * (p_temps / 2));
}

std::string Quaternion::print()
{
    std::string str("");
	//Si le quaternion n'est pas vide, on affiche chaque element suivi d'un espace
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
