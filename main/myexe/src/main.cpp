#pragma once
#include <iostream>
#include <Vecteur3D.hpp>
#include <Matrix3.hpp>
#include <Test_Matrix3.hpp>

//void testVecteur3D();
//void testMatrix3();

int main(void)
{
    // testVecteur3D();
    // testMatrix3();
    Test_Matrix3 testMatrix3;
    testMatrix3.test_creation();
    testMatrix3.test_opération();
    testMatrix3.test_transpose();
    testMatrix3.test_determinant();
    testMatrix3.test_inverse();
    testMatrix3.test_setOrientation();
    std::cin.ignore();

    return 0;
}
/*
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
}*/