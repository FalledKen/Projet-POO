//
// Created by silic on 01/12/2025.
//

#ifndef AFFICHEURGRAPHIQUE_HPP
#define AFFICHEURGRAPHIQUE_HPP

#include "Afficheurs.hpp"
#include "Grille.hpp"
#include <SFML/Graphics.hpp>

class AfficheurGraphique : public Afficheurs {
public:
    // Constructeur avec taille de fenêtre optionnelle
    AfficheurGraphique(int windowSize = 800);

    // Fonction héritée : affiche la grille pour une itération
    void afficher(const Grille& g, int iteration, int tempsParIteration) override;

private:
    int windowSize;
    sf::RenderWindow window; // fenêtre SFML unique
};

#endif // AFFICHEURGRAPHIQUE_HPP
