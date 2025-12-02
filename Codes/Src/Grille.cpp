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
    int count = 0;

    for (int dl = -1; dl <= 1; ++dl) {
        for (int dc = -1; dc <= 1; ++dc) {

            // On ignore la cellule elle-même
            if (dl == 0 && dc == 0)
                continue;

            int nl = l + dl;
            int nc = c + dc;

            // Vérification des bornes
            if (nl >= 0 && nl < nb_lignes &&
                nc >= 0 && nc < nb_colonnes) {

                // Vérifie simplement et uniquement l'état actuel
                if (cellules[nl][nc]->estVivante()) {
                    count++;
                }
                }
        }
    }
    return count;
}

void Grille::grilleSuivante() {
    for (int l = 0; l < nb_lignes; ++l) {
        for (int c = 0; c < nb_colonnes; ++c) {
            cellules[l][c]->calculerEtatSuivant();
        }
    }
}


void Grille::notifierNouvelleGrille() {
    Observable::notifierNouvelleGrille();
}

void Grille::actualiserGrille() {
    for (int l = 0; l < nb_lignes; ++l) {
        for (int c = 0; c < nb_colonnes; ++c) {
            // Applique l'état suivant à l'état actuel
            cellules[l][c]->actualiserEtatSuivant();

            // Réinitialise l'état suivant à mort
            cellules[l][c]->reinitialiserEtatSuivant();
        }
    }
}