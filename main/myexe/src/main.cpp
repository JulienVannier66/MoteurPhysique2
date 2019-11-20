#pragma once
#include <Matrix3.hpp>
#include <Test_Matrix3.hpp>
#include <Vecteur3D.hpp>
#include <iostream>
#include <Quaternion.hpp>
//#include <Test_Quaternion.hpp>
#include <Matrix4.hpp>
//#include <Test_Matrix4.hpp>

// Attention : include une seule classe de test à la fois

// void testVecteur3D();
// void testMatrix3();

int main()
{
    Test_Matrix3 testMatrix3;
    testMatrix3.test_creation();
    testMatrix3.test_opération();
    testMatrix3.test_transpose();
    testMatrix3.test_determinant();
    testMatrix3.test_inverse();
    testMatrix3.test_setOrientation();

    /* Test_Quaternion testQuaternion;
     testQuaternion.test_creation();
     testQuaternion.test_normalize();
     testQuaternion.test_faireRotation();
     testQuaternion.test_updateAngularVelocity();*/

    //Test_Matrix4 testMatrix4;
    //testMatrix4.test_creation();
    ////testMatrix4.test_operation;
    //testMatrix4.test_inverse();
    ////testMatrix4.test_set_orientation;
    //std::cin.ignore();

    return 0;
}