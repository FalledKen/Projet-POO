#include <string>
#include <vector>
#include <iostream>
#include "Fichier.hpp"
#include "Jeu.hpp"
#include "TestsUnitaires.hpp"
#include "ReglesJDLV.hpp"


int main() {
    Jeu jeu;
    bool cle_tests = false;
    jeu.lancerSimulation();
    std::cout << "Effectuer les tests unitaires ? (NON = 0 ; OUI = 1) : ";
    std::cin >> cle_tests;
    if(cle_tests){
        //=====[ TEST UNITAIRES ]=============================//
        RegleJDLV regle;

        //TEST 1 : Clignotant
        std::vector<std::vector<int>> depart1 = {
            {0,1,0},
            {0,1,0},
            {0,1,0}
        };

        std::vector<std::vector<int>> attendue1 = {
            {0,0,0},
            {1,1,1},
            {0,0,0}
        };

        TestsUnitaires t1("Clignonant", depart1, attendue1, 1);
        bool res1 = t1.tester();
        std::cout << "Test Glignotant : " << (res1 ? "SUCCES" : "ECHEC") << std::endl;



        //TEST 2 : Bloc
        std::vector<std::vector<int>> depart2 = {
            {1,1},
            {1,1}
        };
        std::vector<std::vector<int>> attendue2 = {
            {1,1},
            {1,1}
        };

        TestsUnitaires t2("Bloc", depart2, attendue2, 5);
        bool res2 = t2.tester();
        std::cout << "Test Bloc : " << (res2 ? "SUCCES" : "ECHEC") << std::endl;



        //TEST 3 : Diagonale
        std::vector<std::vector<int>> depart3 = {
            {1,0,0},
            {0,1,0},
            {0,0,1}
        };

        std::vector<std::vector<int>> attendue3 = {
            {0,0,0},
            {0,1,0},
            {0,0,0}
        };

        TestsUnitaires t3("Diagonale", depart3, attendue3, 1);
        bool res3 = t3.tester();
        std::cout << "Test Diagonale : " << (res3 ? "SUCCES" : "ECHEC") << std::endl;
    }
    return 0;
}

//le main comme ceci est épuré
