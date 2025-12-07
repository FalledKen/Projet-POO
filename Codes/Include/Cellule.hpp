#ifndef CELLULE_HPP
#define CELLULE_HPP

#include <memory>
#include "Etat.hpp"
#include "Regles.hpp"

class Grille; // prédefinition

class Cellule {
private:
    std::unique_ptr<Etat> etat_actuel;
    std::unique_ptr<Etat> etat_suivant;

    int ligne;
    int colonne;

    Grille* grille;
    Regles* regles;

public:
    Cellule(std::unique_ptr<Etat> etat_initial, int l, int c, Grille* g, Regles* r);

    bool estVivante() const;
    Etat& getEtatActuel() const;
    Etat* getEtatSuivant() const;

    int getLigne() const;
    int getColonne() const;

    void calculerEtatSuivant();
    void actualiserEtatSuivant();
};

#endif
