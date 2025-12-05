//
// Created by silic on 01/12/2025.
//

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

Jeu::Jeu() : g(), r(std::make_unique<RegleJDLV>()) {
    Fichier f;

    // Saisie du nombre d'itérations
    std::cout << "Entrez le nombre d'itérations : ";
    while (true) {
        if (std::cin >> iterations && iterations >= 0) {
            break; // entrée valide
        }

        std::cout << "Valeur invalide. Veuillez entrer un entier >= 0 : ";
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }


    // Saisie du temps par itération (en millisecondes)
    std::cout << "Entrez le temps par itération (en millisecondes) : ";
    while (true) {
        if (std::cin >> tempsParIteration && tempsParIteration >= 0) {
            break;
        }

        std::cout << "Valeur invalide. Veuillez entrer un entier >= 0 : ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Saisie du mode d'affichage
    std::cout << "Choisissez le mode (0 = console, 1 = graphique) : ";
    while (true) {
        if (std::cin >> mode && mode == 0 && mode == 1) {
            break;
        }

        std::cout << "Mode invalide. Entrez 0 pour console ou 1 pour graphique : ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Saisie de  la grille torique
	std::cout << "Voulez-vous une grille torique ? (0 = normale, 1 = torique) : ";
    while (true) {
        if (std::cin >> est_torique && est_torique == 0 && est_torique == 1) {
            break;
        }

        std::cout << "Valeur Invalide. Entrez 0 pour la grille normale ou 1 pour la grille torique : ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Nettoyer la ligne


	std::cout <<"Entrez le nom du fichier : ";
    std::string nom_fichier;
	std::cin >> nom_fichier;
	g.initialisation(f.lire_fichier(nom_fichier), r.get(), est_torique);
}

int Jeu::getIterations() const {
    return iterations;
}

int Jeu::getTempsParIteration() const {
    return tempsParIteration;
}

int Jeu::getMode() const {
   return mode;
}

void Jeu::lancerSimulation() {
    // Demander le nombre d'itérations à l'utilisateur
    std::cout << "Nombre d'itérations : ";
    std::cin >> iterations;

    // Demander le temps par itération (en ms)
    std::cout << "Temps par itération (ms) : ";
    std::cin >> tempsParIteration;

    if (mode == 0) {
        lancerModeConsole();
    } else {
        lancerModeGraphique();
    }
}

void Jeu::lancerModeConsole() {
    AfficheurConsole console;
    for (int i = 0; i < iterations; ++i) {
        console.afficher(g, i, tempsParIteration);
        g.grilleSuivante();
        g.actualiserGrille();
        std::this_thread::sleep_for(std::chrono::milliseconds(tempsParIteration));
    }
}

void Jeu::lancerModeGraphique() {
    AfficheurGraphique graphique;
    for (int i = 0; i < iterations; ++i) {
        graphique.afficher(g, i, tempsParIteration);
        g.grilleSuivante();
        g.actualiserGrille();
        std::this_thread::sleep_for(std::chrono::milliseconds(tempsParIteration));
    }
}
