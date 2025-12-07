#include "Fichier.hpp"
#include "Grille.hpp"
#include "Cellule.hpp"

#include <iostream>
#include <fstream>
#include <filesystem>
#include <sstream>
#include <stdexcept>

Fichier::Fichier() : entree(""), dossier_out("") {}

//demander a lutilisateur le nom du fichier d'entrée
void Fichier::demanderNomFichier() {
    std::cout << "Nom du fichier d'entrée (sans extension .txt) : ";
    std::cin >> entree;
    dossier_out = entree + "_out";
}

//lire le fichier d'entrée et construire la matrice d'entiers
void Fichier::lireFichier() {
    std::ifstream fichier(entree + ".txt");
    if (!fichier.is_open()) {
        throw std::runtime_error("Impossible d'ouvrir le fichier : " + entree);
    }

    matrice.clear();
    std::string ligne;

    //ignorer la première ligne (fait beuger totalemet notre affichage)
    if (!std::getline(fichier, ligne)) {
        throw std::runtime_error("Fichier vide.");
    }

    //lire les lignes suivantes normalement
    while (std::getline(fichier, ligne)) {
        std::vector<int> ligne_vecteur;
        for (char c : ligne) {
            if (c == '0') ligne_vecteur.push_back(0);
            else if (c == '1') ligne_vecteur.push_back(1);
        }

        if (!ligne_vecteur.empty()) {
            matrice.push_back(ligne_vecteur);
        }
    }

    fichier.close();
}


const std::vector<std::vector<int>>& Fichier::getMatrice() const {
    return matrice;
}

//pour créer le dossier de sortie
void Fichier::creerDossierOut() {
    if (std::filesystem::exists(dossier_out)) {
        std::filesystem::remove_all(dossier_out);
    }
    std::filesystem::create_directory(dossier_out);
}


//pour créer un fichier de sortie pour l'iteration donnée
void Fichier::creerFichierOut(int iteration, const Grille& g) {
    std::string nom_fichier = dossier_out + "/iteration_" + std::to_string(iteration) + ".txt";
    std::ofstream sortie(nom_fichier);
    if (!sortie.is_open()) {
        throw std::runtime_error("Impossible de créer le fichier : " + nom_fichier);
    }

    for (int i = 0; i < g.getLignes(); ++i) {
        for (int j = 0; j < g.getColonnes(); ++j) {
            sortie << (g.getCellule(i, j).estVivante() ? '1' : '0');
            sortie << ' ';
        }
        sortie << '\n';
    }

    sortie.close();
}
