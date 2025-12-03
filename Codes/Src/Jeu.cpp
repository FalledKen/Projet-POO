//
// Created by silic on 01/12/2025.
//

#include "Jeu.hpp"

Jeu::Jeu() {
    // Constructeur : initialisation si nécessaire
}

int Jeu::getIterations() const {
    return iterations;
}

int Jeu::getTempsParIteration() const {
    return tempsParIteration;
}

int Jeu::getMode() const {
    return mode;
}

void Jeu::lancerSimulation() {
    // Lancer la simulation selon le mode
}

void Jeu::lancerModeConsole() {
    // Implémentation mode console
}

void Jeu::lancerModeGraphique() {
    // Implémentation mode graphique
}