#pragma once
#include <Assert.hpp>
#include <Debug.hpp>
#include <Matrix4.hpp>
#include <iostream>
#include <windows.h>

class Test_Matrix4
{
private:
    struct Wrong
    {
    };
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

public:
    Test_Matrix4() { std::cout << "----- Start Test_Matrix4 -----" << std::endl; }
    ~Test_Matrix4() { std::cout << "--------------------------------" << std::endl; }

    void test_creation()
    {

        Matrix4 matrice0;

        std::vector<float> myvec;
        myvec.push_back(3);
        myvec.push_back(3);
        myvec.push_back(3);
        myvec.push_back(3);
        myvec.push_back(3);
        myvec.push_back(3);
        myvec.push_back(3);
        myvec.push_back(3);
        myvec.push_back(3);
        myvec.push_back(3);
        myvec.push_back(3);
        myvec.push_back(3);

        Matrix4 matrice1(1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
        Matrix4 matrice2(2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2);

        Matrix4 matrice3(myvec);

        Matrix4 matrice4(matrice1);

        try
        {
            Assert<Wrong>(!CHECK_WRONG || (matrice0.print().compare("")) == 0);
            SetConsoleTextAttribute(hConsole, 10);
            std::cout << "test_Matrice4()_creation0 --- OK" << std::endl;
        } catch (Wrong e)
        {
            SetConsoleTextAttribute(hConsole, 12);
            std::cerr << "test_Matrice4()_creation0 --- KO" << std::endl;
        }

        try
        {
            Assert<Wrong>(!CHECK_WRONG ||
                          (matrice1.print().compare(
                              "1.000000 1.000000 1.000000 1.000000 1.000000 1.000000 1.000000 "
                              "1.000000 1.000000 1.000000 1.000000 1.000000 ")) == 0);
            SetConsoleTextAttribute(hConsole, 10);
            std::cout << "test_Matrice4()_creation1 --- OK" << std::endl;
        } catch (Wrong e)
        {
            SetConsoleTextAttribute(hConsole, 12);
            std::cerr << "test_Matrice4()_creation1 --- KO" << std::endl;
        }

        try
        {
            Assert<Wrong>(!CHECK_WRONG ||
                          (matrice2.print().compare(
                              "2.000000 2.000000 2.000000 2.000000 2.000000 2.000000 2.000000 "
                              "2.000000 2.000000 2.000000 2.000000 2.000000 ")) == 0);
            SetConsoleTextAttribute(hConsole, 10);
            std::cout << "test_Matrice4()_creation2 --- OK" << std::endl;
        } catch (Wrong e)
        {
            SetConsoleTextAttribute(hConsole, 12);
            std::cerr << "test_Matrice4()_creation2 --- KO" << std::endl;
        }

        try
        {
            Assert<Wrong>(!CHECK_WRONG ||
                          (matrice3.print().compare(
                              "3.000000 3.000000 3.000000 3.000000 3.000000 3.000000 3.000000 "
                              "3.000000 3.000000 3.000000 3.000000 3.000000 ")) == 0);
            SetConsoleTextAttribute(hConsole, 10);
            std::cout << "test_Matrice4()_creation3 --- OK" << std::endl;
        } catch (Wrong e)
        {
            SetConsoleTextAttribute(hConsole, 12);
            std::cerr << "test_Matrice4()_creation3 --- KO" << std::endl;
        }

        try
        {
            Assert<Wrong>(!CHECK_WRONG ||
                          (matrice4.print().compare(
                              "1.000000 1.000000 1.000000 1.000000 1.000000 1.000000 1.000000 "
                              "1.000000 1.000000 1.000000 1.000000 1.000000 ")) == 0);
            SetConsoleTextAttribute(hConsole, 10);
            std::cout << "test_Matrice4()_creation4 --- OK" << std::endl;
        } catch (Wrong e)
        {
            SetConsoleTextAttribute(hConsole, 12);
            std::cerr << "test_Matrice4()_creation4 --- KO" << std::endl;
        }
    }

    void test_inverse()
    {
        Matrix4 matrice(1, 0, 1, 0, 2, 1, 1, 2, 0, 2, 1, 2);
        Matrix4 inv = matrice.getInverse();
        Matrix4 matrice_inv_main(-1, 2, -1, 0, -2, 1, 1, -4, 4, -2, -1, 2);
        matrice_inv_main = matrice_inv_main * (1/7);
        try
        {
            Assert<Wrong>(!CHECK_WRONG ||
                          inv.print().compare(matrice_inv_main.print()) == 0);
            SetConsoleTextAttribute(hConsole, 10);
            std::cout << "test_Matrice4()_inverse --- OK" << std::endl;
        } catch (Wrong e)
        {
            SetConsoleTextAttribute(hConsole, 12);
            std::cerr << "test_Matrice4()_inverse --- KO" << std::endl;
        }
    }

    void test_set_orientation() {}
};