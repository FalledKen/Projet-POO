#ifndef FICHIER_HPP
#define FICHIER_HPP

#include <string>
#include <vector>
#include <iostream>
#include "Grille.hpp"
#include "Cellule.hpp"

class Fichier {
private:
    std::string entree;                      // nom du fichier d'entrée
    std::string dossier_out;                 // nom du dossier de sortie
    std::vector<std::vector<int>> matrice;   // matrice lue depuis le fichier

public:
    Fichier();

    void demanderNomFichier();                                // demande le nom du fichier d'entrée via cin
    void lireFichier();                                       // lit le fichier et construit la matrice
    const std::vector<std::vector<int>>& getMatrice() const;  // getter pour la matrice

    void creerDossierOut();                                   // crée le dossier pour les fichiers de sortie
    void creerFichierOut(int iteration, const Grille& g);     // écrit un fichier .txt pour une itération donnée
};

#endif
