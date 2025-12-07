#ifndef AFFICHEURGRAPHIQUE_HPP
#define AFFICHEURGRAPHIQUE_HPP

#include "Afficheurs.hpp"
#include "Grille.hpp"
#include <SFML/Graphics.hpp>

class AfficheurGraphique : public Afficheurs {
private:
    int windowSize;
    sf::RenderWindow window;

public:
    AfficheurGraphique(int windowSize);
    void afficher(const Grille& g, int iteration, int tempsParIteration) override;
};

#endif

