#include "TestsUnitaires.hpp"
#include "Grille.hpp"
#include "ReglesJDLV.hpp"

#include <fstream>

TestsUnitaires::TestsUnitaires(const std::string& nom, const std::vector<std::vector<int>>& depart, const std::vector<std::vector<int>>& attendue, int iter) : matrice_depart(depart), matrice_attendue(attendue), iterations(iter), nom_test(nom){}

bool TestsUnitaires::tester() {

    RegleJDLV regle;

    // On crée une grille locale — PAS DE COPIE !
    Grille g;
    g.initialisation(matrice_depart, &regle);

    // Exécuter la simulation
    for (int i = 0; i < iterations; ++i) {
        g.grilleSuivante();
        g.actualiserGrille();
    }

    // Extraire la grille finale sous forme de matrice
    std::vector<std::vector<int>> resultat(
        g.getLignes(),
        std::vector<int>(g.getColonnes(), 0)
    );

    for (int i = 0; i < g.getLignes(); ++i) {
        for (int j = 0; j < g.getColonnes(); ++j) {
            resultat[i][j] = g.getCellule(i, j).estVivante() ? 1 : 0;
        }
    }

    // Comparaison
    bool succes = (resultat == matrice_attendue);

    // Écriture du fichier résultat
    std::ofstream fichier(nom_test + "_test_result.txt");

    fichier << "Grille de depart :\n";
    for (auto& l : matrice_depart) {
        for (int x : l) fichier << x;
        fichier << '\n';
    }

    fichier << "\nGrille attendue :\n";
    for (auto& l : matrice_attendue) {
        for (int x : l) fichier << x;
        fichier << '\n';
    }

    fichier << "\nGrille obtenue :\n";
    for (auto& l : resultat) {
        for (int x : l) fichier << x;
        fichier << '\n';
    }

    fichier << "\nResultat du test : "
            << (succes ? "Test reussi" : "Test echoue");

    return succes;
}
