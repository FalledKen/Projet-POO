//
// Created by silic on 01/12/2025.
//

#include "RegleJDLV.hpp"

std::unique_ptr<Etat> RegleJDLV::changementEtat(const Etat& etatCourant, int nbVoisines) {
    // Implémentation règles classiques du Jeu de la Vie

    return etatCourant.cloner();
}