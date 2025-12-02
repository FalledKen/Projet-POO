//
// Created by silic on 01/12/2025.
//

#ifndef ETAT_HPP
#define ETAT_HPP

#include <memory>

class Etat {
public:
    virtual ~Etat() = default;

    virtual bool valeur() const = 0;
    virtual std::unique_ptr<Etat> cloner() const = 0;
};

#endif