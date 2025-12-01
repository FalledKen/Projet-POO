//
// Created by silic on 01/12/2025.
//

#include "EtatMort.hpp"

bool EtatMort::valeur() const {
    return false;
}

std::unique_ptr<Etat> EtatMort::cloner() const {
    return std::make_unique<EtatMort>(*this);
}