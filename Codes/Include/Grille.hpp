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
    std::vector<std::vector<std::unique_ptr<Cellule>>> cellules;
    bool est_torique;

public:
    Grille();

    void initialisation(const std::vector<std::vector<int>>& matrice, Regles* regle);
    void setTorique(bool t);

    int getLignes() const;
    int getColonnes() const;

    Cellule& getCellule(int l, int c) const;

    int compterVoisinesVivantes(int l, int c) const;

    void grilleSuivante();
    void actualiserGrille();
};

#endif
