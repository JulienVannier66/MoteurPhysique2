#pragma once
#include <Assert.hpp>
#include <Debug.hpp>
#include <Matrix3.hpp>
#include <iostream>
#include <windows.h>

class Test_RigidBody private : struct Wrong
{
};
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

public:
Test_Matrix3() { std::cout << "----- Start Test_RigidBody -----" << std::endl; }
~Test_Matrix3() { std::cout << "--------------------------------" << std::endl; }

void test_determinant()
{

    try
    {
        Matrix3 matrice_test_determinant(3, -8, 5, -1, 0, 0, 7, -7, -3);
        Assert<Wrong>(!CHECK_WRONG || matrice_test_determinant.determinant() == 59);
        SetConsoleTextAttribute(hConsole, 10);
        std::cout << "determinant --- OK" << std::endl;
    } catch (Wrong e)
    {
        SetConsoleTextAttribute(hConsole, 12);
        std::cerr << "determinant --- KO" << std::endl;
    }
}

void test_creation()
{
    try
    {

        SetConsoleTextAttribute(hConsole, 10);
        std::cout << "constructeur pa défault --- OK" << std::endl;
    } catch (Wrong e)
    {
        SetConsoleTextAttribute(hConsole, 12);
        std::cerr << "constructeur pa défault --- KO" << std::endl;
    }
};