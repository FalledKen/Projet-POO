//
// Created by silic on 01/12/2025.
//

#ifndef GRILLE_HPP
#define GRILLE_HPP

#include <vector>
#include <memory>
#include "Observable.hpp"
#include "Cellule.hpp"

class Grille : public Observable {
private:
    int nb_lignes;
    int nb_colonnes;

    std::vector<std::vector<std::unique_ptr<Cellule>>> cellules;

public:
    Grille(int lignes = 0, int colonnes = 0);

    void initialisation();

    int getLignes() const;
    int getColonnes() const;

    Cellule& getCellule(int l, int c) const;

    int compterVoisinesVivantes(int l, int c) const;

    void grilleSuivante();
    void notifierNouvelleGrille() override;
    void actualiserGrille();
};

#endif