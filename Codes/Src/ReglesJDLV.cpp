#include "ReglesJDLV.hpp"
#include "EtatVivant.hpp"
#include "EtatMort.hpp"

RegleJDLV::RegleJDLV(){
}

std::unique_ptr<Etat> RegleJDLV::changementEtat(const Etat& etatCourant, int nbVoisines) {

    if (etatCourant.valeur() == 1) {
        if (nbVoisines == 2 || nbVoisines == 3){
            return std::make_unique<EtatVivant>();
        }
        else{
            return std::make_unique<EtatMort>();
        }
    }

    else if (etatCourant.valeur() == 0) {
        if (nbVoisines == 3){
            return std::make_unique<EtatVivant>();
        }
        else{
            return std::make_unique<EtatMort>();
        }
    }
    // si jamais aucune condition n'est vérifiée, pour éviter le crash du code...
    return std::make_unique<EtatMort>();
}