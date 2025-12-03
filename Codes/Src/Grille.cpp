//
// Created by silic on 01/12/2025.
//

#include "Grille.hpp"

Grille::Grille(){
    // Initialisation
    nb_lignes = 0;
    nb_colonnes = 0;
}

void Grille::initialisation(std::vector<std::vector<int>> matrice) {
    // Initialisation des cellules
    nb_lignes = matrice.size();
    nb_colonnes = matrice[0].size();

    cellules.resize(nb_lignes);             // on resize la grille (nb de lignes)
    for (int i = 0; i < nb_lignes; i++) {
        cellule[i].resize(nb_colonnes);    // on resize la grille (nb de colonnes)
    }

    for (int i = 0; i < nb_lignes; i++){
        for (int j = 0; j < nb_colonnes; j++){
            if (matrice[i][j] == 0){
                cellule[i][j] = std::make_unique<Cellule>(std::make_unique<EtatMort>(), i, j, this, nullptr);
            }
            else if (matrice[i][j] == 1){
                cellule[i][j] = std::make_unique<Cellule>(std::make_unique<EtatVivant>(), i, j, this, nullptr);
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
    if (l < 0 || c < 0 || l >= nb_lignes || c >= nb_colonnes){
        throw std::out_of_range("Indice cellule hors de la grille !!");
        }
    return *cellule[l][c];
}


int Grille::compterVoisinesVivantes(int l, int c) const {
    int compteur = 0;

    for (int dl = -1; dl <= 1; ++dl) {
        for (int dc = -1; dc <= 1; ++dc) {

            if (dl == 0 && dc == 0)
                continue;

            int nl = l + dl;
            int nc = c + dc;

            // Vérification des bornes
            if (nl >= 0 && nl < nb_lignes &&
                nc >= 0 && nc < nb_colonnes) {

                // Vérifie simplement et uniquement l'état actuel
                if (cellule[nl][nc]->estVivante()) {
                    compteur++;
                }
                }
        }
    }
    return compteur;
}

void Grille::grilleSuivante() {
    for (int i = 0; l < nb_lignes; ++l) {
        for (int j = 0; c < nb_colonnes; ++c) {
            cellule[i][j]->calculerEtatSuivant();
        }
    }
}

void Grille::actualiserGrille() {
    int cpt;
    for (int l = 0; l < nb_lignes; ++l) {
        for (int c = 0; c < nb_colonnes; ++c) {
            // pour chaque cellule : etat_actuel = eta_suivant et on met etat_suivant a nullptr ensuite
            if (cellule[l][c]::getEtatActuel() == cellule[l][c]->getEtatSuivant()) {
                cpt++;
            }
            cellule[l][c]->actualiserEtatSuivant();
        }
    }
    if (cpt == nb_lignes*nb_colonnes) {
            /* Fonction de fin*/
}
}
