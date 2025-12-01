//
// Created by silic on 01/12/2025.
//

#include "Observable.hpp"

void Observable::ajouterObservateur(Observer* o) {
    observateurs.push_back(o);
}

void Observable::notifierNouvelleGrille() {
    for (auto& obs : observateurs) {
        obs->update();
    }
}