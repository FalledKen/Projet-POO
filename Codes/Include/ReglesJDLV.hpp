#ifndef REGLEJDLV_HPP
#define REGLEJDLV_HPP

#include "Regles.hpp"

class RegleJDLV : public Regles {
public:
    RegleJDLV();
    std::unique_ptr<Etat> changementEtat(const Etat& etatCourant, int nbVoisines) override;
};

#endif
