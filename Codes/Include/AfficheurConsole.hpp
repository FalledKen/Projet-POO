#ifndef AFFICHEURCONSOLE_HPP
#define AFFICHEURCONSOLE_HPP

#include "Afficheurs.hpp"
#include "Fichier.hpp"
#include "Grille.hpp"

class AfficheurConsole : public Afficheurs {
private:
    Fichier& ecriture;

public:
    AfficheurConsole(Fichier& ecriture_);
    void afficher(const Grille& g, int iteration, int tempsParIteration) override;
};

#endif
