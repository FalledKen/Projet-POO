//
// Created by celes on 03/12/2025.
//

#include "../Include/Fichier.hpp"
#include <fstream>
#include <iostream>
#include <vector>

bool nouveau_fichier(const std::string& nom_fichier) {
    std::ofstream fichier(nom_fichier);

    if (fichier) {
        fichier << "3 5" << std::endl;
        fichier << "0 0 1 0 0" << std::endl;
        fichier.close();
        return false;
    }
    return true;
}

bool ajout_dans_fichier(const std::string& nom_fichier) {
    std::ofstream fichier(nom_fichier, std::ofstream::app); // Ajoute au fichier

    if (fichier) {
        fichier << "0 1 1 0 0" << std::endl;
        fichier << "0 1 0 1 0" << std::endl;
        fichier.close();
        return false;
    }
    return true;
}

bool lire_fichier(const std::string& nom_fichier) {
    std::ifstream fichier(nom_fichier); // Lire un fichier
    if (!fichier) {
        return true;
    }

    std::vector<std::string> contenu_fichier;
    int nb_ligne, nb_colonnes;

    fichier >> nb_ligne >> nb_colonnes;

    std::cout << "Lignes = " << nb_ligne << ", Colonnes = " << nb_colonnes << "\n";

    std::vector<std::vector<int>> matrice(nb_ligne, std::vector<int>(nb_colonnes));

    for (int i = 0; i < nb_ligne; i++) {
        for (int j = 0; j < nb_colonnes; j++) {
            fichier >> matrice[i][j];
            std::cout << matrice[i][j] << " ";
        }
        std::cout << "\n";
    }

    fichier.close();

    return false;
}