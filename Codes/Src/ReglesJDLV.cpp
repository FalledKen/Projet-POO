//
// Created by silic on 01/12/2025.
//

#include "RegleJDLV.hpp"

RegleJDLV::RegleJDLV(){
}

std::unique_ptr<Etat> RegleJDLV::changementEtat(const Etat& etatCourant, int nbVoisines) override {

    if (etatCourant.valeur() == 1) {
        if (nbVoisines == 2 || nbVoisines == 3){
            return std::make_unique<EtatVivant>();
        }
        else{
            return std::make_unique<EtatMort>();
        }
    }

    else if (etatCourant.valeur() == 0) {
        if (nbVoisines == 3){
            return std::make_unique<EtatVivant>();
        }
        else{
            return std::make_unique<EtatMort>();
        }
    }
}