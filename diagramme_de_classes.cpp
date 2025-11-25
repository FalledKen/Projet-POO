classDiagram

    class Jeu{ 
    }

    class Grille{
        -int nbLignes
        -int nbColonnes
        -vector< vector< Cellule*>> grille_du_jeu
        -bool est_torique : BONUS*
        +Grille()
    }

    class Cellule{
        -bool etat
        -bool suivant
        -bool est_obstacle : BONUS*
        +Cellule()
        +Cellule(bool etat_initial)
        +bool estVivante() virtual
        +void chgmtEtat()
    }

    class Morte{
        +bool estVivante() override
    }

    class Vivante{
        +bool estVivante() override
    }

    class Regles
    
Cellule <|-- Morte
Cellule <|-- Vivante

    
