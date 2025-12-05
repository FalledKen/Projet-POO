//
// Created by celes on 03/12/2025.
//

#ifndef FICHIER_HPP
#define FICHIER_HPP

#include <vector>
#include <string>

class Fichier {
public:
    static bool creer_dossier(const std::string& nom_fichier);
    static bool ecrire_fichier(const std::vector<std::vector<int>>& matrice,
                               const std::string& nom_fichier, int iteration);
    static std::vector<std::vector<int>> lire_fichier(const std::string& nom_fichier_seul);
    static std::vector<std::vector<int>> convertir_matrice_pointeurs(
            const std::vector<std::vector<int*>>& matrice_ptr);
};

#endif
