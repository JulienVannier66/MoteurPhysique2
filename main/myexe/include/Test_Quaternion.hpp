#pragma once
#include <Assert.hpp>
#include <Debug.hpp>
#include <Quaternion.hpp>
#include <cmath>
#include <iostream>
#include <windows.h>

class Test_Quaternion
{
private:
    struct Wrong
    {
    };
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

public:
    Test_Quaternion() { std::cout << "----- Start Test_Quaternion -----" << std::endl; }
    ~Test_Quaternion() { std::cout << "--------------------------------" << std::endl; }

    void test_creation()
    {

        std::vector<float> vector_for_quater;

        vector_for_quater.push_back(0.5f);
        vector_for_quater.push_back(0.5f);
        vector_for_quater.push_back(0.5f);
        vector_for_quater.push_back(0.5f);

        Quaternion quater1;
        Quaternion quater2(vector_for_quater);
        Quaternion quater3(quater2);

        // std::vector<float> vec;
        // for (int i = 0; i < 9; i++) { vec.push_back(1); }
        // Matrix3 matrice4(vec);
        try
        {
            std::string str(quater1.print());
            Assert<Wrong>(!CHECK_WRONG || (quater1.print().compare("")) == 0);
            SetConsoleTextAttribute(hConsole, 10);
            std::cout << "test_Quaternion() --- OK" << std::endl;
        } catch (Wrong e)
        {
            SetConsoleTextAttribute(hConsole, 12);
            std::cerr << "test_Quaternion() --- KO" << std::endl;
        }
        try
        {
            Assert<Wrong>(!CHECK_WRONG ||
                          quater2.print().compare("0.500000 0.500000 0.500000 0.500000 ") == 0);
            SetConsoleTextAttribute(hConsole, 10);
            std::cout << "test_Quaternion(via vector) --- OK" << std::endl;
        } catch (Wrong e)
        {
            SetConsoleTextAttribute(hConsole, 12);
            std::cerr << "test_Quaternion(via vector) --- KO" << std::endl;
        }

        try
        {
            Assert<Wrong>(!CHECK_WRONG ||
                          quater3.print().compare("0.500000 0.500000 0.500000 0.500000 ") == 0);
            SetConsoleTextAttribute(hConsole, 10);
            std::cout << "test_Matrix3(Matrix3) --- OK" << std::endl;
        } catch (Wrong e)
        {
            SetConsoleTextAttribute(hConsole, 12);
            std::cerr << "test_Matrix3(Matrix3) --- KO" << std::endl;
        }
    }

    void test_normalize()
    {
        std::vector<float> vector_for_quater;
        std::vector<float> vector_for_quater2;

        vector_for_quater.push_back(1);
        vector_for_quater.push_back(2);
        vector_for_quater.push_back(3);
        vector_for_quater.push_back(4);

        vector_for_quater2.push_back(0);
        vector_for_quater2.push_back(0);
        vector_for_quater2.push_back(0);
        vector_for_quater2.push_back(0);

        float l_un_sur_racine_de_trente;
        l_un_sur_racine_de_trente = 1 / (sqrt(30));
        std::cout << std::to_string(l_un_sur_racine_de_trente) << std::endl;

        Quaternion quater(vector_for_quater);
        Quaternion quater2(vector_for_quater2);

        quater.normalize();
        quater2.normalize();

        try
        {
            std::string str(quater.print());
            // Assert<Wrong>(!CHECK_WRONG ||
            // (quater.print().compare("1.000000 2.000000 3.000000 4.000000 ")) == 0);
            Assert<Wrong>(!CHECK_WRONG || (quater.getAt(0) == l_un_sur_racine_de_trente &&
                                           quater.getAt(1) == 2 * l_un_sur_racine_de_trente &&
                                           quater.getAt(2) == 3 * l_un_sur_racine_de_trente &&
                                           quater.getAt(3) == 4 * l_un_sur_racine_de_trente));
            SetConsoleTextAttribute(hConsole, 10);
            std::cout << "test_Quaternion()_normalize --- OK" << std::endl;
        } catch (Wrong e)
        {
            SetConsoleTextAttribute(hConsole, 12);
            std::cerr << "test_Quaternion()_normalize --- KO" << std::endl;
        }

        try
        {
            std::string str(quater2.print());
            // Assert<Wrong>(!CHECK_WRONG ||
            // (quater.print().compare("1.000000 2.000000 3.000000 4.000000 ")) == 0);
            Assert<Wrong>(!CHECK_WRONG || (quater2.getAt(0) == 1));
            SetConsoleTextAttribute(hConsole, 10);
            std::cout << "test_Quaternion()_normalize_for_no_rotation --- OK" << std::endl;
        } catch (Wrong e)
        {
            SetConsoleTextAttribute(hConsole, 12);
            std::cerr << "test_Quaternion()_normalize_for no rotation --- KO" << std::endl;
        }
    }

    void test_faireRotation()
    {
        std::vector<float> vector_for_quater;

        float pi = atan(1) * 4;
        Vecteur3D myvec(0, pi, 0);

        // std::cout << "Vecteur" << std::endl;
        // std::cout << std::to_string(myvec.getX()) << std::endl;
        // std::cout << std::to_string(myvec.getY()) << std::endl;
        // std::cout << std::to_string(myvec.getZ()) << std::endl;

        vector_for_quater.push_back(0.5f);
        vector_for_quater.push_back(0.5f);
        vector_for_quater.push_back(0.5f);
        vector_for_quater.push_back(0.5f);

        Quaternion quater(vector_for_quater);
        quater.faireRotation(myvec);

        // std::cout << std::to_string(quater.getAt(0)) << std::endl;
        // std::cout << std::to_string(quater.getAt(1)) << std::endl;
        // std::cout << std::to_string(quater.getAt(2)) << std::endl;
        // std::cout << std::to_string(quater.getAt(3)) << std::endl;

        try
        {
            std::string str(quater.print());
            Assert<Wrong>(!CHECK_WRONG ||
                          (quater.getAt(0) == -pi / 2 && quater.getAt(1) == pi / 2 &&
                           quater.getAt(2) == pi / 2 && quater.getAt(3) == -pi / 2));
            SetConsoleTextAttribute(hConsole, 10);
            std::cout << "test_Quaternion()_faireRotation --- OK" << std::endl;
        } catch (Wrong e)
        {
            SetConsoleTextAttribute(hConsole, 12);
            std::cerr << "test_Quaternion()_faireRotation --- KO" << std::endl;
        }
    }

    void test_updateAngularVelocity()
    {

        std::vector<float> vector_for_quater;

        float pi = atan(1) * 4;
        Vecteur3D myvec(0, pi, 0);

        vector_for_quater.push_back(0.5f);
        vector_for_quater.push_back(0.5f);
        vector_for_quater.push_back(0.5f);
        vector_for_quater.push_back(0.5f);

        Quaternion quater(vector_for_quater);
        quater.updateAngularVelocity(myvec, 2);

        //std::cout << std::to_string(quater.getAt(0)) << std::endl;
        //std::cout << std::to_string(quater.getAt(1)) << std::endl;
        //std::cout << std::to_string(quater.getAt(2)) << std::endl;
        //std::cout << std::to_string(quater.getAt(3)) << std::endl;

        try
        {
            std::string str(quater.print());
            Assert<Wrong>(!CHECK_WRONG ||
                          (quater.getAt(0) == (1 - pi) / 2 && quater.getAt(1) == (1 + pi) / 2 &&
                           quater.getAt(2) == (1 + pi) / 2 && quater.getAt(3) == (1 - pi) / 2));
            SetConsoleTextAttribute(hConsole, 10);
            std::cout << "test_Quaternion()_updateangularvelocity --- OK" << std::endl;
        } catch (Wrong e)
        {
            SetConsoleTextAttribute(hConsole, 12);
            std::cerr << "test_Quaternion()_updateangularvelocity --- KO" << std::endl;
        }
    }
};