#pragma once
#include <Matrix3.hpp>
#include <Vecteur3D.hpp>
#include <iostream>
//#include <Test_Matrix3.hpp>
#include <Quaternion.hpp>
//#include <Test_Quaternion.hpp>
#include <Matrix4.hpp>
#include <Test_Matrix4.hpp>

// Attention : include une seule classe de test à la fois

// void testVecteur3D();
// void testMatrix3();

int main()
{
    // testVecteur3D();
    // testMatrix3();

    // Test_Matrix3 testMatrix3;
    // testMatrix3.test_creation();
    // testMatrix3.test_opération();
    // testMatrix3.test_transpose();
    // testMatrix3.test_determinant();
    // testMatrix3.test_inverse();

    /* Test_Quaternion testQuaternion;
     testQuaternion.test_creation();
     testQuaternion.test_normalize();
     testQuaternion.test_faireRotation();
     testQuaternion.test_updateAngularVelocity();*/

    Test_Matrix4 testMatrix4;
    testMatrix4.test_creation();
    //testMatrix4.test_operation;
    testMatrix4.test_inverse();
    //testMatrix4.test_set_orientation;

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