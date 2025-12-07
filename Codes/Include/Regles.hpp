#ifndef REGLES_HPP
#define REGLES_HPP

#include <memory>
#include "Etat.hpp"

class Regles {
public:
    virtual ~Regles() = default;
    virtual std::unique_ptr<Etat> changementEtat(const Etat& etatCourant, int nbVoisines) = 0;
};

#endif
