//
// Created by silic on 01/12/2025.
//

#ifndef JEU_HPP
#define JEU_HPP

#include "Grille.hpp"
#include "Regles.hpp"
#include "Afficheurs.hpp"

class Jeu {
private:
    Grille grille_du_jeu;
    Regles* regles_du_jeu;

    int iterations;
    int tempsParIteration;
    int mode;

    void lancerModeConsole();
    void lancerModeGraphique();

public:
    Jeu();
    void lancerSimulation();
    int getIterations();
    int getTempsParIteration();
    int getMode();

};

#endif