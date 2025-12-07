#include "AfficheurConsole.hpp"
#include <iostream>
#include <thread>
#include <chrono>

AfficheurConsole::AfficheurConsole(Fichier& ecriture_) : ecriture(ecriture_) {}



void AfficheurConsole::afficher(const Grille& g, int iteration, int tempsParIteration) {

    // AFFICHAGE DANS LA CONSOLE
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    std::cout << "Itération " << iteration << " :\n";
    for (int i = 0; i < g.getLignes(); ++i) {
        for (int j = 0; j < g.getColonnes(); ++j) {
            std::cout << (g.getCellule(i, j).estVivante() ? "□" : "■");
            //std::cout << ' ';
        }
        std::cout << '\n';
    }
    std::cout << std::endl;

    // ECRITURE DU FICHIER
    ecriture.creerFichierOut(iteration, g);

    // INTERVALLE CHOSI PAR L'UTILISATEUR
    std::this_thread::sleep_for(std::chrono::milliseconds(tempsParIteration));
}
