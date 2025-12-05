//
// Created by silic on 01/12/2025.
//

#ifndef ETATVIVANT_HPP
#define ETATVIVANT_HPP

#include "Etat.hpp"

class EtatVivant : public Etat {
public:
    EtatVivant();
    bool valeur() const override;
    std::unique_ptr<Etat> cloner() const override;
};

#endif