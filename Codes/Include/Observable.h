//
// Created by silic on 01/12/2025.
//

#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP

#include <vector>
#include "Observer.hpp"

class Observable {
protected:
    std::vector<Observer*> observateurs;

public:
    virtual ~Observable() = default;

    virtual void ajouterObservateur(Observer* o);
    virtual void notifierNouvelleGrille();
};

#endif