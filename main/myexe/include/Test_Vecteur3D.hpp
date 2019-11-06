#include <Assert.hpp>
#include <Debug.hpp>
#include <Vecteur3D.hpp>
#include <iostream>

class Test_Vecteur3D
{
private:
    struct Wrong
    {
    };

public:
    Test_Vecteur3D() { std::cout << "----- Start Test_Vecteur3D -----" << std::endl; }
    ~Test_Vecteur3D() { std::cout << "--------------------------------" << std::endl; }

    void test_creation()
    {
        try
        {
            Vecteur3D p_vecteur(2, 6, 7);

            Assert<Wrong>(!CHECK_WRONG || p_vecteur.print().compare("[2;6;7]"));
            std::cout << "test_creationVecteur3D --- OK" << std::endl;
        } catch (Wrong e)
        {
            std::cerr << "test_creationVecteur3D --- KO" << std::endl;
        }

        /*

        v3 = v - v2;
        std::cout << v3 << "\n";

        v3 = v * 2;
        std::cout << v3 << "\n";

        v3 = v ^ v2;
        std::cout << v3 << "\n";

        std::cout << v.produitScalaire(v2) << "\n";
        std::cout << v.norme() << "\n";
        std::cout << v2.norme() << "\n";*/
    }

    void test_addition()
    {
        try
        {
            Vecteur3D p_vecteur(2, 6, 7);
            Vecteur3D p_vecteur2(8, 4, 3);
            Vecteur3D p_vecteurResult;

			p_vecteurResult = p_vecteur + p_vecteur2;
            Assert<Wrong>(!CHECK_WRONG || p_vecteurResult.print().compare("[10;10;10]"));
            std::cout << "test_addition --- OK" << std::endl;
        } catch (Wrong e)
        {
            std::cerr << "test_addition --- KO" << std::endl;
        }
    }
};