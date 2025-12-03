//
// Created by silic on 01/12/2025.
//

#include "AfficheurConsole.hpp"
#include <iostream>

void AfficheurConsole::afficher(const Grille& g, int iterations) {
    const int colonnes = g.getHauteur();
    const int lignes = g.getLignes();

    std::cout << "Iteration" << std::endl;
for (int y = 0; y < colonnes; ++y) {
for (int x = 0; x < lignes; ++x) {

    const Cellule& c = g.getCellule(x);

    bool vivante = c.estVivante();

    std::cout << (vivante ? 'X' : '.');
}
    std::cout << '\n';
}
    std::cout << std::endl;
}