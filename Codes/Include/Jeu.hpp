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
    Grille g;
    std::unique_ptr<Regles> r;

    int iterations;
    int TempsParIteration;
    int mode;
    bool est_torique;

    void lancerModeConsole();
    void lancerModeGraphique();

public:
    Jeu();
    void lancerSimulation();
    int getIterations() const;
    int getTempsParIteration() const;
    int getMode() const;

};

#endif