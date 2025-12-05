//
// Created by celes on 03/12/2025.
//

#include "../Include/Fichier.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <filesystem>

bool Fichier::creer_dossier(const std::string& nom_fichier) {
    const std::string nom_dossier = nom_fichier + "_out";
    std::filesystem::path dir = nom_dossier;

    if (std::filesystem::create_directory(dir)) {
        std::cout << dir << " créé avec succès.\n";
        return false;
    }

    std::cout << "Le dossier existe déjà ou n'a pas pu être créé.\n";
    return true;
}

bool Fichier::ecrire_fichier(const std::vector<std::vector<int>> &matrice, const std::string& nom_fichier, const int iteration) {
    std::string dir = nom_fichier + "_out/iteration_";
    dir += std::to_string(iteration);
    dir += ".txt";
    std::ofstream fichier(dir);

    if (!fichier) {
        return true;
    }

    const size_t nb_lignes = matrice.size();
    const size_t nb_colonnes = matrice[0].size();
    fichier << nb_lignes << " " << nb_colonnes << "\n";

    for (size_t i = 0; i < nb_lignes; i++) {
        for (size_t j = 0; j < nb_colonnes; j++) {
            fichier << matrice[i][j] << " ";
        }
        fichier << "\n";
    }
    fichier.close();
    return false;
}

std::vector<std::vector<int>> Fichier::lire_fichier(const std::string& nom_fichier_seul) {
    const std::string nom_fichier = nom_fichier_seul + ".txt";
    std::ifstream fichier(nom_fichier); // Lire un fichier

    if (!fichier) {
        std::cerr << "Impossible d'ouvrir le fichier." << std::endl;
    }

    int nb_ligne, nb_colonnes;
    fichier >> nb_ligne >> nb_colonnes;

    //std::cout << "Lignes = " << nb_ligne << ", Colonnes = " << nb_colonnes << "\n";

    std::vector<std::vector<int>> matrice(nb_ligne, std::vector<int>(nb_colonnes));

    for (int i = 0; i < nb_ligne; i++) {
        for (int j = 0; j < nb_colonnes; j++) {
            fichier >> matrice[i][j];
            //std::cout << matrice[i][j] << " ";
        }
        //std::cout << "\n";
    }

    fichier.close();

    return matrice;
}

std::vector<std::vector<int>> Fichier::convertir_matrice_pointeurs(
        const std::vector<std::vector<int*>>& matrice_ptr)
{
    std::vector<std::vector<int>> matrice;
    matrice.resize(matrice_ptr.size());

    for (size_t i = 0; i < matrice_ptr.size(); i++) {
        matrice[i].resize(matrice_ptr[i].size());

        for (size_t j = 0; j < matrice_ptr[i].size(); j++) {
            if (matrice_ptr[i][j] != nullptr) {
                matrice[i][j] = *(matrice_ptr[i][j]);  // copie de la valeur
            } else {
                matrice[i][j] = 0;  // valeur par défaut si pointeur nul
            }
        }
    }

    return matrice;
}
