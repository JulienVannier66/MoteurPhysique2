#include <iostream>
#include <Vecteur3D.hpp>

void testVecteur3D();

int main(void)
{
    testVecteur3D();
    std::cin.ignore();
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