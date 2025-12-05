//
// Created by silic on 01/12/2025.
//

#include "Grille.hpp"
#include "Cellule.hpp"
#include "EtatVivant.hpp"
#include "EtatMort.hpp"
#include "Regles.hpp"

#include <memory>
#include <vector>
#include <stdexcept>

Grille::Grille()
    : nb_lignes(0), nb_colonnes(0), estTorique(false) {}

void Grille::initialisation(std::vector<std::vector<int>> matrice,
                            Regles* regles,
                            bool estTorique) 
{
    this->estTorique = estTorique;

    nb_lignes = matrice.size();
    nb_colonnes = matrice[0].size();

    cellules.resize(nb_lignes);
    for (int i = 0; i < nb_lignes; i++) {
        cellules[i].resize(nb_colonnes);
    }

    for (int i = 0; i < nb_lignes; i++) {
        for (int j = 0; j < nb_colonnes; j++) {

            if (matrice[i][j] == 0) {
                cellules[i][j] = std::make_unique<Cellule>(
                    std::make_unique<EtatMort>(), i, j, this, regles
                );
            } 
            else {
                cellules[i][j] = std::make_unique<Cellule>(
                    std::make_unique<EtatVivant>(), i, j, this, regles
                );
            }
        }
    }
}

int Grille::getLignes() const {
    return nb_lignes;
}

int Grille::getColonnes() const {
    return nb_colonnes;
}

Cellule& Grille::getCellule(int l, int c) const {
    if (l < 0 || c < 0 || l >= nb_lignes || c >= nb_colonnes) {
        throw std::out_of_range("Indice cellule hors de la grille !");
    }
    return *cellules[l][c];
}

int Grille::compterVoisinesVivantes(int l, int c) const {
    int compteur = 0;

    for (int dl = -1; dl <= 1; ++dl) {
        for (int dc = -1; dc <= 1; ++dc) {

            if (dl == 0 && dc == 0)
                continue;

            int nl = l + dl;
            int nc = c + dc;

            if (estTorique) {
                // Wrap torique
                nl = (nl + nb_lignes) % nb_lignes;
                nc = (nc + nb_colonnes) % nb_colonnes;
            } 
            else {
                // Hors-bord → on ignore
                if (nl < 0 || nl >= nb_lignes || nc < 0 || nc >= nb_colonnes)
                    continue;
            }

            if (cellules[nl][nc]->estVivante()) {
                compteur++;
            }
        }
    }

    return compteur;
}

void Grille::grilleSuivante() {
    for (int l = 0; l < nb_lignes; ++l) {
        for (int c = 0; c < nb_colonnes; ++c) {
            cellules[l][c]->calculerEtatSuivant();
        }
    }
}

void Grille::actualiserGrille() {
    for (int l = 0; l < nb_lignes; ++l) {
        for (int c = 0; c < nb_colonnes; ++c) {
            cellules[l][c]->actualiserEtatSuivant();
        }
    }
}

std::vector<std::vector<int>> Grille::toIntMatrix() const {
    std::vector<std::vector<int>> matrice(nb_lignes, std::vector<int>(nb_colonnes));

    for (int i = 0; i < nb_lignes; i++) {
        for (int j = 0; j < nb_colonnes; j++) {
            matrice[i][j] = cellules[i][j]->estVivante() ? 1 : 0;
        }
    }

    return matrice;
}
