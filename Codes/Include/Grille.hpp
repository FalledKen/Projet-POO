//
// Created by silic on 01/12/2025.
//
#ifndef GRILLE_HPP
#define GRILLE_HPP

#include <vector>
#include <memory>
#include "Cellule.hpp"
#include "Regles.hpp"

class Grille {
private:
    int nb_lignes;
    int nb_colonnes;
    bool estTorique;

    std::vector<std::vector<std::unique_ptr<Cellule>>> cellules;

public:
    Grille();

    void initialisation(std::vector<std::vector<int>> matrice, Regles* regles, bool estTorique);

    int getLignes() const;
    int getColonnes() const;

    Cellule& getCellule(int l, int c) const;

    int compterVoisinesVivantes(int l, int c) const;

    void grilleSuivante();
    void actualiserGrille();
};

#endif