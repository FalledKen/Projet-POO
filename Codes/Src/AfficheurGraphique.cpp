#include "AfficheurGraphique.hpp"
#include <thread>
#include <chrono>
#include <string>

AfficheurGraphique::AfficheurGraphique(int size) : windowSize(size), window(sf::VideoMode(size, size), "Jeu de la Vie"){
    window.setFramerateLimit(60);
}


void AfficheurGraphique::afficher(const Grille& g, int iteration, int tempsParIteration) {

    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed){
            window.close();
        }
    }

    window.clear(sf::Color::Black);

    int lignes = g.getLignes();
    int colonnes = g.getColonnes();

    float largeurCellule = static_cast<float>(windowSize) / colonnes;
    float hauteurCellule = static_cast<float>(windowSize) / lignes;

    float dimension;

    if (hauteurCellule > largeurCellule){
        dimension = largeurCellule;
    }

    else{
        dimension = hauteurCellule;
    }

    sf::RectangleShape cellule(sf::Vector2f(dimension, dimension));

    // choix des couleurs :
    sf::Color couleurVivante(0, 100, 250);  // bleu clair
    sf::Color couleurMorte(0, 0, 50);       // bleu foncé
    sf::Color bordure(0, 20, 100);          // bleu entre les deux précédents (contraste suffiasnt)

    cellule.setOutlineColor(bordure);
    cellule.setOutlineThickness(3.f);

    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {

            if (g.getCellule(i, j).estVivante()){
                cellule.setFillColor(couleurVivante);
            }
            else if (not g.getCellule(i, j).estVivante()){
                cellule.setFillColor(couleurMorte);
            }
            cellule.setPosition(j*dimension, i*dimension);
            window.draw(cellule);
        }
    }

    window.setTitle("Jeu de la Vie - Iteration " + std::to_string(iteration));
    window.display();

    std::this_thread::sleep_for(std::chrono::milliseconds(tempsParIteration));
}
