#include <iostream>
#include <Vecteur3D.hpp>
#include <Matrix3.hpp>

void testVecteur3D();
void testMatrix3();

int main(void)
{
    testVecteur3D();
    testMatrix3();
    std::cin.ignore();
}

void testMatrix3() 
{
    std::cout << "------debut test Matrix3-------" << std::endl;
	Matrix3 matrice;
    std::string str (matrice.print());
    std::cout << "constructeur par default : " << str.compare("1.000000 0.000000 0.000000 0.000000 1.000000 0.000000 0.000000 0.000000 1.000000 ")  << std::endl;

	std::vector<float> vec;
    for (int i = 0; i < 9; i++)
	{
		vec.push_back(1); 
	}
    Matrix3 matrice2(vec);
    std::string str2(matrice2.print());
    std::cout << "constructeur value avec vecteur: " << str2.compare("1.000000 1.000000 1.000000 1.000000 1.000000 1.000000 1.000000 1.000000 1.000000 ") << std::endl;

	Matrix3 matrice5(1, 0, 0, 1, 1, 0, 1, 1, 1);
    std::string str10(matrice5.print());
    std::cout << "constructeur value avec 9 float: " << str10.compare("1.000000 0.000000 0.000000 1.000000 1.000000 0.000000 1.000000 1.000000 1.000000 ") << std::endl;

	Matrix3 matrice3;
    matrice3 = matrice2;
    std::string str3(matrice3.print());
    std::cout << "operateur = : " << str3.compare("1.000000 1.000000 1.000000 1.000000 1.000000 1.000000 1.000000 1.000000 1.000000 ") << std::endl;


    std::string str4((matrice2 + matrice3).print());
    std::cout << "operateur + : " << str4.compare("2.000000 2.000000 2.000000 2.000000 2.000000 2.000000 2.000000 2.000000 2.000000 ") << std::endl;

	matrice2 += matrice3;
    std::string str5(matrice2.print());
    std::cout << "operateur += : " << str5.compare("2.000000 2.000000 2.000000 2.000000 2.000000 2.000000 2.000000 2.000000 2.000000 ") << std::endl;

    std::string str6((matrice2*matrice).print());
    std::cout << "operateur * (identite): " << str6.compare("2.000000 2.000000 2.000000 2.000000 2.000000 2.000000 2.000000 2.000000 2.000000 ") << std::endl;
    std::string str7((matrice2 * matrice3).print());
    std::cout << "operateur * (matrice avec que des 2 * matrice avec que des 1): " << str7.compare("6.000000 6.000000 6.000000 6.000000 6.000000 6.000000 6.000000 6.000000 6.000000 ") << std::endl;

	matrice2 *= matrice;
	std::string str8(matrice2.print());
    std::cout << "operateur *= (identite): " << str8.compare("2.000000 2.000000 2.000000 2.000000 2.000000 2.000000 2.000000 2.000000 2.000000 ") << std::endl;
    matrice2 *= matrice3;
    std::string str9(matrice2.print());
    std::cout << "operateur *= (matrice avec que des 2 * matrice avec que des 1): " << str9.compare("6.000000 6.000000 6.000000 6.000000 6.000000 6.000000 6.000000 6.000000 6.000000 ") << std::endl;

    matrice2 *= 3;
    std::string str11(matrice2.print());
    std::cout << "operateur *= (matrice avec que des 6 * float(3)): "
              << str11.compare("18.000000 18.000000 18.000000 18.000000 18.000000 18.000000 18.000000 18.000000 18.000000 ") << std::endl;

	matrice5.transpose();
    std::string str12(matrice5.print());
        std::cout << "transposee(): "
                  << str12.compare("1.000000 1.000000 1.000000 0.000000 1.000000 1.000000 0.000000 0.000000 1.000000 ")
                  << std::endl;

	
}

void testVecteur3D()
{
    std::cout << "Hello World!\n";
    Vecteur3D v(2, 6, 7);
    Vecteur3D v2(4, -6, 3);
    Vecteur3D v3;

    std::cout << v << "\n";
    std::cout << v2 << "\n";
    std::cout << v3 << "\n";

    v3 = v + v2;
    std::cout << v3 << "\n";

    v3 = v - v2;
    std::cout << v3 << "\n";

    v3 = v * 2;
    std::cout << v3 << "\n";

    v3 = v ^ v2;
    std::cout << v3 << "\n";

    std::cout << v.produitScalaire(v2) << "\n";
    std::cout << v.norme() << "\n";
    std::cout << v2.norme() << "\n";
}