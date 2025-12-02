//
// Created by silic on 01/12/2025.
//

#ifndef AFFICHEURGRAPHIQUE_HPP
#define AFFICHEURGRAPHIQUE_HPP

#include "Afficheurs.hpp"

class AfficheurGraphique : public Afficheurs {
public:
    void afficher(const Grille& g, int iterations) override;
};

#endif