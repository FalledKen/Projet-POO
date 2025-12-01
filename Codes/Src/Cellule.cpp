//
// Created by silic on 01/12/2025.
//

#include "Cellule.hpp"
#include "Grille.hpp"
#include "Regles.hpp"

Cellule::Cellule(std::unique_ptr<Etat> etat_initial, int l, int c, Grille* g, Regles* r)
    : etat_actuel(std::move(etat_initial)), ligne(l), colonne(c), grille(g), regles(r) {
}

void Cellule::update() {
    // Mise à jour de l'état
}

void Cellule::calculerEtatSuivant() {
    // Calculer état suivant
}

void Cellule::appliquerEtatSuivant() {
    // Appliquer état suivant
}

bool Cellule::estVivante() const {
    return etat_actuel->valeur();
}

Etat& Cellule::getEtatActuel() const {
    return *etat_actuel;
}