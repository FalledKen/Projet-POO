//
// Created by silic on 01/12/2025.
//

#include "EtatVivant.hpp"

EtatVivant::EtatVivant(){
}

bool EtatVivant::valeur() const {
    return true;
}

std::unique_ptr<Etat> EtatVivant::cloner() const {
    return std::make_unique<EtatVivant>(*this);
}