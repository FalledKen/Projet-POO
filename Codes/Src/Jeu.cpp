#include <iostream>
#include <limits>
#include <thread>
#include <chrono>

#include "Cellule.hpp"
#include "Jeu.hpp"
#include "Etat.hpp"
#include "EtatMort.hpp"
#include "EtatVivant.hpp"
#include "AfficheurConsole.hpp"
#include "AfficheurGraphique.hpp"
#include "Afficheurs.hpp"
#include "Grille.hpp"
#include "Regles.hpp"
#include "ReglesJDLV.hpp"
#include "Fichier.hpp"


Jeu::Jeu() : g(), r(std::make_unique<RegleJDLV>()), iterations(0), tempsParIteration(0), mode(0){
   
    // demander puis lire le fichier
    fichier.demanderNomFichier();
    fichier.lireFichier();
    
    // demander grille toriuqe ou pas
    bool est_torique = false;
    std::cout << "Grille torique ? (0 = Non ; 1 = Oui) : ";
    while (true) {
        if (std::cin >> est_torique && (est_torique == 0 || est_torique == 1))
            break;

        std::cout << "INVALIDE !!! --> Entrez 0 ou 1 : ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    g.setTorique(est_torique);

    // initialiser la grille grâce au fichier
    g.initialisation(fichier.getMatrice(), r.get());

    // demander le nombre d'itérations
    std::cout << "Nombre d'itérations : ";
    while (true) {
        if (std::cin >> iterations && iterations >= 0)
            iterations += 1;
            break;

        std::cout << "INVALIDE !!! --> Entrez un nombre supérieur à 0 : ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // demander le temps entre chaque itération
    std::cout << "Temps entre chaque itération (en ms) : ";
    while (true) {
        if (std::cin >> tempsParIteration && tempsParIteration >= 0)
            break;

        std::cout << "INVALIDE !!! --> Entrez un nombre supérieur à 0 : ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    /// choix du mode
    std::cout << "Mode ? (0 = Mode Console ; 1 = Mode Graphique) : ";
    while (true) {
        if (std::cin >> mode && (mode == 0 || mode == 1))
            break;

        std::cout << "INVALIDE !!! --> Entrez 0 ou 1 : ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    //création du dossier de sortie : <nom_fichier_entree>_out
    fichier.creerDossierOut();
}


int Jeu::getIterations() const{ 
    return iterations; 
}

int Jeu::getTempsParIteration() const{ 
    return tempsParIteration; 
}

int Jeu::getMode() const{ 
    return mode; 
}


void Jeu::lancerSimulation() {
    if (mode == 0){
        lancerModeConsole();
    }
        
    else if (mode == 1){
        lancerModeGraphique();
    }     
}








/// =====[ MODE CONSOLE ]======= ///
void Jeu::lancerModeConsole() {
    AfficheurConsole console(fichier);

    for (int i = 0; i < iterations; ++i) {
        console.afficher(g, i, tempsParIteration);
        g.grilleSuivante();
        g.actualiserGrille();
        std::this_thread::sleep_for(std::chrono::milliseconds(tempsParIteration));
    }
}


/// =====[ MODE GRAPHIQUE ]======= ///
void Jeu::lancerModeGraphique() {
    AfficheurGraphique graphique(900); 

    for (int i = 0; i < iterations; ++i) {
        graphique.afficher(g, i, tempsParIteration);
        g.grilleSuivante();
        g.actualiserGrille();
    }
}