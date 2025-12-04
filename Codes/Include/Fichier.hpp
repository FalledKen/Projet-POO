//
// Created by celes on 03/12/2025.
//

#ifndef PROJET_POO_FICHIER_H
#define PROJET_POO_FICHIER_H

#include <string>
#include <iostream>
#include <vector>

class Fichier {
public:
    bool creer_dossier(const std::string& nom_fichier);
    bool ecrire_fichier(const std::vector<std::vector<int>> &matrice, const std::string& nom_fichier, const int iteration);
    std::vector<std::vector<int>> lire_fichier(const std::string& nom_fichier);
};

#endif