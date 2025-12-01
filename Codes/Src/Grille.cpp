//
// Created by silic on 01/12/2025.
//

#include "Grille.hpp"

Grille::Grille(int lignes, int colonnes)
    : nb_lignes(lignes), nb_colonnes(colonnes) {
    // Initialisation
}

void Grille::initialisation() {
    // Initialisation des cellules
}

int Grille::getLignes() const {
    return nb_lignes;
}

int Grille::getColonnes() const {
    return nb_colonnes;
}

Cellule& Grille::getCellule(int l, int c) const {
    return *cellules[l][c];
}

int Grille::compterVoisinesVivantes(int l, int c) const {
    // Retourner le nombre de voisines vivantes
    return 0;
}

void Grille::notifierNouvelleGrille() {
    Observable::notifierNouvelleGrille();
}

void Grille::actualiserGrille() {
    // Calculer la grille suivante
}