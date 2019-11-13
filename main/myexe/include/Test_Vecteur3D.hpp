#include <Assert.hpp>
#include <Debug.hpp>
#include <Vecteur3D.hpp>
#include <iostream>
#include <windows.h> 

class Test_Vecteur3D
{
private:
    struct Wrong
    {
    };
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

public:
    Test_Vecteur3D() { std::cout << "----- Start Test_Vecteur3D -----" << std::endl; }
    ~Test_Vecteur3D() { std::cout << "--------------------------------" << std::endl; }

    void test_creation()
    {
        try
        {
            Assert<Wrong>(!CHECK_WRONG || 1==1); //
            SetConsoleTextAttribute(hConsole, 10); //
            std::cout << "test_creationVecteur3D --- OK" << std::endl; //
        } catch (Wrong e) //
        {
            SetConsoleTextAttribute(hConsole, 12); //
            std::cerr << "test_creationVecteur3D --- KO" << std::endl; //
        }
    }

    void test_addition()
    {
        try
        {
            Vecteur3D p_vecteur(2, 6, 7);
            Vecteur3D p_vecteur2(8, 4, 3);
            Vecteur3D p_vecteurResult;
            std::string l_result;

			p_vecteurResult = p_vecteur + p_vecteur2;
            l_result = p_vecteurResult.print();
            Assert<Wrong>(!CHECK_WRONG || l_result == "[10;10;10]");
            SetConsoleTextAttribute(hConsole, 10);
            std::cout << "test_addition + --- OK" << std::endl;
        } catch (Wrong e)
        {
            SetConsoleTextAttribute(hConsole, 12);
            std::cerr << "test_addition + --- KO" << std::endl;
        }
    }

	void test_additionVecteurCourant()
    {
        try
        {
            Vecteur3D p_vecteur(2, 6, 7);
            Vecteur3D p_vecteur2(8, 4, 3);
            std::string l_result("[10;10;10]");

            p_vecteur += p_vecteur2;
            Assert<Wrong>(!CHECK_WRONG || l_result.compare(p_vecteur.print()) == 0);
            SetConsoleTextAttribute(hConsole, 10);
            std::cout << "test_addition += --- OK" << std::endl;
        } catch (Wrong e)
        {
            SetConsoleTextAttribute(hConsole, 12);
            std::cerr << "test_addition += --- KO" << std::endl;
        }
    }
};