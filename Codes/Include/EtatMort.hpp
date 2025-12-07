#ifndef ETATMORT_HPP
#define ETATMORT_HPP

#include "Etat.hpp"

class EtatMort : public Etat {
public:
    EtatMort();
    bool valeur() const override;
    std::unique_ptr<Etat> cloner() const override;
};

#endif