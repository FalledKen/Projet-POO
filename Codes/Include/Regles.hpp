//
// Created by silic on 01/12/2025.
//

#ifndef REGLES_HPP
#define REGLES_HPP

#include <memory>
#include "Etat.hpp"

class Regles {
public:
    virtual std::unique_ptr<Etat> changementEtat(const Etat& etatCourant, int nbVoisines) = 0;
    virtual ~Regles() = default;
};

#endif