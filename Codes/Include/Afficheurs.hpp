#ifndef AFFICHEURS_HPP
#define AFFICHEURS_HPP

#include "Grille.hpp"

class Afficheurs {
public:
    virtual ~Afficheurs() = default;
    virtual void afficher(const Grille& g, int iterations, int tempsParIteration) = 0;
};

#endif
