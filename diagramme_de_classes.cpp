classDiagram
class Jeu {
    -Grille grille_du_jeu
    -Regles* regles_du_jeu
    -Fichier fichier_du_jeu
    -int iterations
    -int tempsParIteration
    -int mode
    +Jeu()
    +int getIterations() const
    +int getTempsParIteration() const
    +int getMode() const
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
    -Fichier ecriture
    +void afficher(const Grille& g, int iterations) override
}
class AfficheurGraphique {
    +void afficher(const Grille& g, int iterations) override
}
Jeu o-- Afficheurs
Afficheurs <|-- AfficheurGraphique
Afficheurs <|-- AfficheurConsole


class Fichier {
    -string nom
    -string dossier_out
    -vector< vector< int>> matrice
    +Fichier()
    +void demanderNomFichier()
    +void lireFichier()
    +const vector<vector<int>>& getMatrice() const
    +int getLignes() const 
    +int getColonnes() const
    +void creerDossierOut()
    +void creerFichierOut(int iteration, const Grille& g)
}
Grille ..> Fichier
AfficheurConsole ..> Fichier


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
    +void initialisation(vector< vector< int>> matrice)
    +int getLignes() const
    +int getColonnes() const
    +Cellule& getCellule(int l, int c) const
    +int compterVoisinesVivantes(int l, int c) const
    +void ajouterObservateur(Observer* o)
    +void notifierNouvelleGrille() override
    +void grilleSuivante()
    +void actualiserGrille()
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
    +void actualiserEtatSuivant()
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













