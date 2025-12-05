//
// Created by silic on 01/12/2025.
//

#ifndef AFFICHEURCONSOLE_HPP
#define AFFICHEURCONSOLE_HPP

#include "Afficheurs.hpp"
#include "Grille.hpp"
#include "Regles.hpp"

class AfficheurConsole : public Afficheurs {
public:
    void afficher(const Grille& g, int iterations, int tempsParIteration) override;
};

#endif
