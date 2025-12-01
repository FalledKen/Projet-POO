//
// Created by silic on 01/12/2025.
//

#ifndef REGLEJDLV_HPP
#define REGLEJDLV_HPP

#include "Regles.hpp"

class RegleJDLV : public Regles {
public:
    std::unique_ptr<Etat> changementEtat(const Etat& etatCourant, int nbVoisines) override;
};

#endif