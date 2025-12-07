#include "Cellule.hpp"
#include "Grille.hpp"
#include "Regles.hpp"


Cellule::Cellule(std::unique_ptr<Etat> etat_initial, int l, int c, Grille* g, Regles* r)
    : etat_actuel(std::move(etat_initial)), etat_suivant(nullptr), ligne(l), colonne(c), grille(g), regles(r) {
}

bool Cellule::estVivante() const {
    return etat_actuel->valeur();
}

Etat& Cellule::getEtatActuel() const {
    return *etat_actuel;
}

Etat* Cellule::getEtatSuivant() const {
    return etat_suivant.get();
}

int Cellule::getLigne() const {
    return ligne;
}

int Cellule::getColonne() const {
    return colonne;
}

void Cellule::calculerEtatSuivant() {
    int voisines = grille->compterVoisinesVivantes(ligne, colonne);
    etat_suivant = regles->changementEtat(*etat_actuel, voisines);
}

void Cellule::actualiserEtatSuivant() {
    if (etat_suivant != nullptr){
        etat_actuel = std::move(etat_suivant);
    }
}