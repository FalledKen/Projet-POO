//
// Created by silic on 01/12/2025.
//

#ifndef AFFICHEURS_HPP
#define AFFICHEURS_HPP

#include "Grille.hpp"

class Afficheurs {
public:
    virtual ~Afficheurs() = default;
    virtual void afficher(const Grille& g, int iterations) = 0;
};

#endif