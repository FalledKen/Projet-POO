//
// Created by silic on 01/12/2025.
//

#include <string>
#include <vector>
#include <iostream>
#include "Include/Fichier.hpp"
#include "Include/Jeu.hpp"

int main() {
    Jeu jeu;
    jeu.lancerSimulation();

    // =====[ FICHIER ]=====
    Fichier file;

    const std::string nom_fichier = "grille";

    const std::vector<std::vector<int>> matrice = file.lire_fichier(nom_fichier);

    file.creer_dossier(nom_fichier);

    for (int i = 0; i < 10; i++) {
        file.ecrire_fichier(matrice, nom_fichier, i);
    }

    return 0;
}
