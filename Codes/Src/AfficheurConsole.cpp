//
// Created by silic on 01/12/2025.
//
#include "AfficheurConsole.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

void AfficheurConsole::afficher(const Grille& g, int iteration, int tempsParIteration) {

    const int hauteur = g.getLignes();  // nombre de lignes
    const int largeur = g.getColonnes();  // nombre de colonnes

    // Création de la matrice 0/1
    std::vector<std::vector<int>> matrice(hauteur, std::vector<int>(largeur));

    std::cout << "Iteration : " << iteration << "\n";

    for (int y = 0; y < hauteur; ++y) {
        for (int x = 0; x < largeur; ++x) {

            Cellule& c = g.getCellule(y, x);

            bool vivante = c.estVivante();

            // Affichage console (X = vivante, . = morte)
            std::cout << (vivante ? 'X' : '.');

            // Remplissage de la matrice 1/0
            matrice[y][x] = vivante ? 1 : 0;
        }
        std::cout << '\n';
    }

    std::cout << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(tempsParIteration));
}
