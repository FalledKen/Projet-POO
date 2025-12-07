#ifndef JEU_HPP
#define JEU_HPP

#include <memory>
#include "Grille.hpp"
#include "Regles.hpp"
#include "Afficheurs.hpp"
#include "Fichier.hpp"

class Jeu {
private:
    Grille g;
    std::unique_ptr<Regles> r;
    Fichier fichier;

    int iterations;
    int tempsParIteration;
    int mode;

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
