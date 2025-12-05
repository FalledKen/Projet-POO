//
// Created by silic on 01/12/2025.
//

#ifndef REGLESJDLV_HPP
#define REGLESJDLV_HPP

#include "Regles.hpp"
#include "EtatVivant.hpp"
#include "EtatMort.hpp"

class RegleJDLV : public Regles {
public:
    RegleJDLV();
    std::unique_ptr<Etat> changementEtat(const Etat& etatCourant, int nbVoisines) override;
};

#endif