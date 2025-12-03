//
// Created by silic on 01/12/2025.
//

#include "AfficheurGraphique.hpp"
#include <thread>
#include <chrono>
#include <string>

AfficheurGraphique::AfficheurGraphique(int size)
    : windowSize(size),
      window(sf::VideoMode(size, size), "Jeu de la Vie") {
    // Fenêtre SFML initialisée
}

void AfficheurGraphique::afficher(const Grille& g, int iteration, int tempsParIteration) {
    if (!window.isOpen())
        return;

    // Gestion des événements (fermeture)
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    // Efface la fenêtre précédente
    window.clear(sf::Color::Black);

    int rows = g.getLignes();
    int cols = g.getColonnes();
    float cellWidth = static_cast<float>(windowSize) / cols;
    float cellHeight = static_cast<float>(windowSize) / rows;

    // Dessiner toutes les cellules
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            const Cellule& cell = g.getCellule(i, j);
            sf::RectangleShape rectangle(sf::Vector2f(cellWidth, cellHeight));
            rectangle.setPosition(j * cellWidth, i * cellHeight);
            rectangle.setFillColor(cell.estVivante() ? sf::Color::White : sf::Color::Black);
            window.draw(rectangle);
        }
    }

    // Mettre à jour le titre avec le numéro d'itération
    window.setTitle("Itération " + std::to_string(iteration));

    // Afficher le contenu
    window.display();

    // Pause selon le temps par itération
    std::this_thread::sleep_for(std::chrono::milliseconds(tempsParIteration));
}
