#pragma once
#include <Assert.hpp>
#include <Debug.hpp>
#include <Matrix3.hpp>
#include <iostream>
#include <windows.h>

class Test_Matrix3
{
private:
    struct Wrong
    {
    };
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

public:
    Test_Matrix3() { std::cout << "----- Start Test_Matrix3 -----" << std::endl; }
    ~Test_Matrix3() { std::cout << "--------------------------------" << std::endl; }

    void test_creation()
    {
        Matrix3 matrice1;
        Matrix3 matrice2(1, 1, 1, 1, 1, 1, 1, 1, 1);
        Matrix3 matrice3(matrice2);
        std::vector<float> vec;
        for (int i = 0; i < 9; i++) { vec.push_back(1); }
        Matrix3 matrice4(vec);
        try
        {
            std::string str(matrice1.print());
            Assert<Wrong>(!CHECK_WRONG ||
                          (matrice1.print().compare("1.000000 0.000000 0.000000 0.000000 1.000000 "
                                                    "0.000000 0.000000 0.000000 1.000000 ")) == 0);
            SetConsoleTextAttribute(hConsole, 10);
            std::cout << "test_Matrix3() --- OK" << std::endl;
        } catch (Wrong e)
        {
            SetConsoleTextAttribute(hConsole, 12);
            std::cerr << "test_Matrix3() --- KO" << std::endl;
        }
        try
        {
            Assert<Wrong>(!CHECK_WRONG ||
                          matrice2.print().compare("1.000000 1.000000 1.000000 1.000000 1.000000 "
                                                   "1.000000 1.000000 1.000000 1.000000 ") == 0);
            SetConsoleTextAttribute(hConsole, 10);
            std::cout << "test_Matrix3(floatx9) --- OK" << std::endl;
        } catch (Wrong e)
        {
            SetConsoleTextAttribute(hConsole, 12);
            std::cerr << "test_Matrix3(floatx9) --- KO" << std::endl;
        }
        try
        {
            Assert<Wrong>(!CHECK_WRONG ||
                          matrice3.print().compare("1.000000 1.000000 1.000000 1.000000 1.000000 "
                                                   "1.000000 1.000000 1.000000 1.000000 ") == 0);
            SetConsoleTextAttribute(hConsole, 10);
            std::cout << "test_Matrix3(Matrix3) --- OK" << std::endl;
        } catch (Wrong e)
        {
            SetConsoleTextAttribute(hConsole, 12);
            std::cerr << "test_Matrix3(Matrix3) --- KO" << std::endl;
        }
        try
        {
            Assert<Wrong>(!CHECK_WRONG ||
                          matrice4.print().compare("1.000000 1.000000 1.000000 1.000000 1.000000 "
                                                   "1.000000 1.000000 1.000000 1.000000 ") == 0);
            SetConsoleTextAttribute(hConsole, 10);
            std::cout << "test_Matrix3(Vector<float>) --- OK" << std::endl;
        } catch (Wrong e)
        {
            SetConsoleTextAttribute(hConsole, 12);
            std::cerr << "test_Matrix3(Vector<float>) --- KO" << std::endl;
        }
    }

    void test_opération()
    {
        Matrix3 matriceid;
        Matrix3 matrice1(1, 1, 1, 1, 1, 1, 1, 1, 1);
        Matrix3 matrice2(2, 2, 2, 2, 2, 2, 2, 2, 2);
        try
        {
            Matrix3 matrice_test_equal;
            matrice_test_equal = matrice1;
            Assert<Wrong>(!CHECK_WRONG ||
                          matrice_test_equal.print().compare(matrice1.print()) == 0);
            SetConsoleTextAttribute(hConsole, 10);
            std::cout << "operateur = --- OK" << std::endl;
        } catch (Wrong e)
        {
            SetConsoleTextAttribute(hConsole, 12);
            std::cerr << "operateur = --- KO" << std::endl;
        }
        try
        {
            Matrix3 matrice_test_plus(matrice1 + matrice2);
            Assert<Wrong>(!CHECK_WRONG || matrice_test_plus.print().compare(
                                              "3.000000 3.000000 3.000000 3.000000 3.000000 "
                                              "3.000000 3.000000 3.000000 3.000000 ") == 0);
            matrice_test_plus = matrice_test_plus + matriceid;
            Assert<Wrong>(!CHECK_WRONG || matrice_test_plus.print().compare(
                                              "4.000000 3.000000 3.000000 3.000000 4.000000 "
                                              "3.000000 3.000000 3.000000 4.000000 ") == 0);
            SetConsoleTextAttribute(hConsole, 10);
            std::cout << "operateur + --- OK" << std::endl;
        } catch (Wrong e)
        {
            SetConsoleTextAttribute(hConsole, 12);
            std::cerr << "operateur + --- KO" << std::endl;
        }
        try
        {
            Matrix3 matrice_test_plus_equal;
            matrice_test_plus_equal += matriceid;
            Assert<Wrong>(!CHECK_WRONG || matrice_test_plus_equal.print().compare(
                                              "2.000000 0.000000 0.000000 0.000000 2.000000 "
                                              "0.000000 0.000000 0.000000 2.000000 ") == 0);
            matrice_test_plus_equal += matrice2;
            Assert<Wrong>(!CHECK_WRONG || matrice_test_plus_equal.print().compare(
                                              "4.000000 2.000000 2.000000 2.000000 4.000000 "
                                              "2.000000 2.000000 2.000000 4.000000 ") == 0);
            SetConsoleTextAttribute(hConsole, 10);
            std::cout << "operateur += --- OK" << std::endl;
        } catch (Wrong e)
        {
            SetConsoleTextAttribute(hConsole, 12);
            std::cerr << "operateur += --- KO" << std::endl;
        }
        try
        {
            Matrix3 matrice_test_mult(matrice1 * matriceid);
            Assert<Wrong>(!CHECK_WRONG || matrice_test_mult.print().compare(matrice1.print()) == 0);
            matrice_test_mult = matrice2 * matrice1;
            Assert<Wrong>(!CHECK_WRONG || matrice_test_mult.print().compare(
                                              "6.000000 6.000000 6.000000 6.000000 6.000000 "
                                              "6.000000 6.000000 6.000000 6.000000 ") == 0);
            SetConsoleTextAttribute(hConsole, 10);
            std::cout << "operateur * --- OK" << std::endl;
        } catch (Wrong e)
        {
            SetConsoleTextAttribute(hConsole, 12);
            std::cerr << "operateur * --- KO" << std::endl;
        }
        try
        {
            Matrix3 matrice_test_mult_equal(matrice2);
            matrice_test_mult_equal *= matrice1;
            Assert<Wrong>(!CHECK_WRONG || matrice_test_mult_equal.print().compare(
                                              (matrice2 * matrice1).print()) == 0);
            SetConsoleTextAttribute(hConsole, 10);
            std::cout << "operateur *=(matrice) --- OK" << std::endl;
        } catch (Wrong e)
        {
            SetConsoleTextAttribute(hConsole, 12);
            std::cerr << "operateur *=(matrice) --- KO" << std::endl;
        }

        try
        {
            Matrix3 matrice_test_mult_equal(matrice2);
            matrice_test_mult_equal *= 4;
            Assert<Wrong>(!CHECK_WRONG || matrice_test_mult_equal.print().compare(
                                              "8.000000 8.000000 8.000000 8.000000 8.000000 "
                                              "8.000000 8.000000 8.000000 8.000000 ") == 0);
            SetConsoleTextAttribute(hConsole, 10);
            std::cout << "operateur *=(float) --- OK" << std::endl;
        } catch (Wrong e)
        {
            SetConsoleTextAttribute(hConsole, 12);
            std::cerr << "operateur *=(float) --- KO" << std::endl;
        }
        try
        {
            Vecteur3D vec(4, -3, 2);
            Matrix3 matrice_test_mult_vec(4.0f, 2.0f, -2.0f, 6.0f, 13.0f, -2.0f, 5.6f, 8.2f, 7.1f);
            std::cout << "matrice" << matrice_test_mult_vec.print() << std::endl;
            std::cout << "vec" << vec.print() << std::endl;
            std::cout << "mult vec" << (matrice_test_mult_vec * vec).print() << std::endl;
            Assert<Wrong>(!CHECK_WRONG || (matrice_test_mult_vec * vec).print() ==
                                              "[6.000000;-19.000000;12.000001]");
            SetConsoleTextAttribute(hConsole, 10);
            std::cout << "operateur *(Vecteur3D) --- OK" << std::endl;
        } catch (Wrong e)
        {
            SetConsoleTextAttribute(hConsole, 12);
            std::cerr << "operateur *(Vecteur3D) --- KO" << std::endl;
        }
    }

    void test_transpose()
    {
        try
        {
            Matrix3 matrice_test_transpose(1, 0, 0, 1, 1, 0, 1, 1, 1);
            matrice_test_transpose.transpose();
            Matrix3 matrice_temoin(1, 1, 1, 0, 1, 1, 0, 0, 1);
            Assert<Wrong>(!CHECK_WRONG ||
                          matrice_test_transpose.print().compare(matrice_temoin.print()) == 0);
            SetConsoleTextAttribute(hConsole, 10);
            std::cout << "transpose --- OK" << std::endl;
        } catch (Wrong e)
        {
            SetConsoleTextAttribute(hConsole, 12);
            std::cerr << "transpose --- KO" << std::endl;
        }
    }

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

    void test_inverse()
    {
        try
        {
            Matrix3 matrice_test_inverse(3, -8, 5, -1, 0, 0, 7, -7, -3);
            matrice_test_inverse.inverse();
            double x1 = -3.0f / 59.0f;
            double x2 = -44.0f / 59.0f;
            double x3 = -5.0f / 59.0f;
            double x4 = 7.0f / 59.0f;
            double x5 = -35.0f / 59.0f;
            double x6 = -8.0f / 59.0f;
            Matrix3 matrice_temoin(0.0f, -1.0f, 0.0f, x1, x2, x3, x4, x5, x6);
            Assert<Wrong>(!CHECK_WRONG ||
                          matrice_test_inverse.print().compare(matrice_temoin.print()) == 0);
            SetConsoleTextAttribute(hConsole, 10);
            std::cout << "inverse --- OK" << std::endl;
        } catch (Wrong e)
        {
            SetConsoleTextAttribute(hConsole, 12);
            std::cerr << "inverse --- KO" << std::endl;
        }
    }

    void test_setOrientation()
    {
        try
        {
            std::vector<float> vec;
            vec.push_back(3);
            vec.push_back(1);
            vec.push_back(-1);
            vec.push_back(-7);
            Quaternion quat(vec);
            Matrix3 matrice_test_setOrientation = Matrix3::setOrientation(quat);
            Matrix3 matrice_temoin(-3, 20, 8, -8, -19, -44, -20, 40, -19);
            Assert<Wrong>(!CHECK_WRONG || matrice_test_setOrientation.print().compare(matrice_temoin.print()) == 0);
            SetConsoleTextAttribute(hConsole, 10);
            std::cout << "setOrientation --- OK" << std::endl;
        } catch (Wrong e)
        {
            SetConsoleTextAttribute(hConsole, 12);
            std::cerr << "setOrientation --- KO" << std::endl;
        }
    }
}; 