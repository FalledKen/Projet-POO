//
// Created by silic on 01/12/2025.
//

#ifndef CELLULE_HPP
#define CELLULE_HPP

#include <memory>
#include "Etat.hpp"

class Grille;
class Regles;

class Cellule : public Observer {

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
    Etat& getEtatSuivant() const;
    void calculerEtatSuivant();
    void actualiserEtatSuivant();

};


#endif