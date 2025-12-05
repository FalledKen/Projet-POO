#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "TestsUnitaires.hpp"
#include "Fichier.hpp"
#include "Cellule.hpp"

//rajouter des include si besoin

TestsUnitaires::TestsUnitaires(){
  
}

void TestsUnitaires::testInitialisationGrille(){
  
}

void TestsUnitaires::testCompterVoisines(){
}

void TestsUnitaires::testEvolutionCellule(){
    //Cellule c;
    //c.calculerEtatSuivant();
}

void TestsUnitaires::testLectureFichier(){
    Fichier file;
    std::vector<std::vector<int>> matrice;
    
    matrice = file.lire_fichier("test_grille");

    int nb_lignes = matrice.size();
    int nb_colonnes = matrice[0].size();

    std::cout << "Lignes = " << nb_lignes << ", Colonnes = " << nb_colonnes << "\n";

    for (int i = 0; i < nb_lignes; i++) {
        for (int j = 0; j < nb_colonnes; j++) {
            std::cout << matrice[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void TestsUnitaires::testEcritureFichier(){
    Fichier file;
    const std::vector<std::vector<int>> matrice = {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 1, 1, 0, 0}};

    if (file.ecrire_fichier(matrice, "test_grille", 1)) {
        std::cout << "Un problème est survenu..." << std::endl;
    }
}