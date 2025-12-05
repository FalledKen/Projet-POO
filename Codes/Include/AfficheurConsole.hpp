//
// Created by silic on 01/12/2025.
//

#ifndef AFFICHEURCONSOLE_HPP
#define AFFICHEURCONSOLE_HPP

#include "Afficheurs.hpp"

class AfficheurConsole : public Afficheurs {
private:
    Fichier ecriture;
public:
    AfficheurConsole(Fichier ecriture_);
    void afficher(const Grille& g, int iterations, int tempsParIteration) override;
};

#endif