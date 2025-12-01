classDiagram
class Jeu {
    -Grille grille_du_jeu
    -Regles* regles_du_jeu
    -int iterationsMax
    -int tempsParIteration
    -int mode
    +Jeu()
    +void lancerSimulation()
    -void lancerModeConsole()
    -void lancerModeGraphique()
}
Jeu o-- Grille : "possède"
Jeu ..> Regles : "utilise"


class Afficheurs{
    +virtual void afficher(const Grille& g, int iterations) 
}
class AfficheurConsole {
    +void afficher(const Grille& g, int iterations) override
}
class AfficheurGraphique {
    +void afficher(const Grille& g, int iterations) override
}
Jeu o-- Afficheurs
Afficheurs <|-- AfficheurGraphique
Afficheurs <|-- AfficheurConsole




class Observer {
    <<interface>>
    +virtual void update() = 0
}
class Observable {
    <<interface>>
    -vector< Observer*> observateurs
    +virtual void ajouterObservateur(Observer* o)
    +virtual void notifierNouvelleGrille()
}



class Grille {
    -int nb_lignes
    -int nb_colonnes
    -vector< vector< unique_ptr< Cellule>>> cellules
    +Grille()
    +void initialisation()
    +int getLignes() const
    +int getColonnes() const
    +Cellule& getCellule(int l, int c) const
    +int compterVoisinesVivantes(int l, int c) const
    +void ajouterObservateur(Observer* o)
    +void notifierNouvelleGrille() override
    +void actualiserGrille() override
}
Grille o-- Cellule : "contient"
Grille --|> Observable
Regles .. Grille : "utilise"





class Cellule {
    -unique_ptr< Etat> etat_actuel
    -unique_ptr< Etat> etat_suivant
    -int ligne
    -int colonne
    -Grille* grille
    -Regles* regles
    +Cellule(unique_ptr< Etat> etat_initial, int l, int c, Grille* g, Regles* r)
    +void update() override
    +void calculerEtatSuivant()
    +void appliquerEtatSuivant()
    +bool estVivante() const
    +Etat& getEtatActuel() const
}
Cellule o-- Etat : "possède"
Cellule --|> Observer





class Etat {
    <<abstract>>
    +virtual bool valeur() const
    +virtual unique_ptr< Etat> cloner() const
    +virtual ~Etat()
}
class EtatVivant {
    +bool valeur() const override
    +unique_ptr< Etat> cloner() const override
}
class EtatMort {
    +bool valeur() const override
    +unique_ptr< Etat> cloner() const override
}
Etat <|-- EtatVivant
Etat <|-- EtatMort






class Regles {
    <<abstract>>
    +virtual unique_ptr< Etat> changementEtat(const Etat& etatCourant, int nbVoisines) = 0
}
class RegleJDLV {
    +unique_ptr< Etat> changementEtat(const Etat& etatCourant, int nbVoisines) override
}
Regles <|-- RegleJDLV
Regles .. Cellule : "utilise"













