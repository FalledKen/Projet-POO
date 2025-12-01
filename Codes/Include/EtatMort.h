//
// Created by silic on 01/12/2025.
//

#ifndef ETATMORT_HPP
#define ETATMORT_HPP

#include "Etat.hpp"

class EtatMort : public Etat {
public:
    bool valeur() const override;
    std::unique_ptr<Etat> cloner() const override;
};

#endif