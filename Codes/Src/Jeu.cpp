//
// Created by silic on 01/12/2025.
//

#include "Cellule.hpp"
#include "Jeu.hpp"
#include "Etat.hpp"
#include "EtatMort.hpp"
#include "EtatVivant.hpp"
#include "AfficheurConsole.hpp"
#include "AfficheurGraphique.hpp"
#include "Afficheurs"
#include "Grille.hpp"
#include "Regles.hpp"
#include "ReglesJDLV.hpp"
#include "Fichier.hpp"

Jeu::Jeu() {
	grille = new Grille();
    // Saisie sécurisée du nombre d'itérations
    std::cout << "Entrez le nombre d'itérations : ";
    while (!(std::cin >> iterations) || iterations < 0) {
        std::cout << "Valeur invalide. Veuillez entrer un entier >= 0 : ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Saisie sécurisée du temps par itération (en millisecondes)
    std::cout << "Entrez le temps par itération (en millisecondes) : ";
    while (!(std::cin >> tempsParIteration) || tempsParIteration < 0) {
        std::cout << "Valeur invalide. Veuillez entrer un entier >= 0 : ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Saisie sécurisée du mode d'affichage
    std::cout << "Choisissez le mode (0 = console, 1 = graphique) : ";
    while (!(std::cin >> mode) || (mode != 0 && mode != 1)) {
        std::cout << "Mode invalide. Entrez 0 pour console ou 1 pour graphique : ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
	std::cout << "La grille est-elle torique ?") : ";
    while (!(std::cin >> est_torique) || (est_torique != 0 && est_torique != 1)) {
        std::cout << "Valeur Invalide. Entrez 0 pour la grille normale ou 1 pour la grille torique : ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Nettoyer la ligne

	std::cout <<"Entrez le nom du fichier : ";
	std:: cin >> nom_fichier;
	grille.initialisation(lire_fichier(nom_fichier_seul);
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

   Fichier(file);
	grille.initialisation(file.lire_fichier(nom_fichier));
    if (mode == 0) {
        lancerModeConsole();
    } else {
        lancerModeGraphique();
    }
}

void Jeu::lancerModeConsole() {
    AfficheurConsole afficheur;
    for (int i = 0; i < iterations; ++i) {
        afficheur.afficher(grille, i);
        grille.grilleSuivante();
        grille.actualiserGrille();
        std::this_thread::sleep_for(std::chrono::milliseconds(tempsParIteration));
    }
}

void Jeu::lancerModeGraphique() {
    AfficheurGraphique afficheurGraphique;
    for (int i = 0; i < iterations; ++i) {
        afficheurGraphique.afficher(grille, i, tempsParIteration);
        Grille.grilleSuivante();
        Grille.actualiserGrille();
        std::this_thread::sleep_for(std::chrono::milliseconds(tempsParIteration));
    }
}
