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
    <<abstract>>
    +virtual void afficher(const Grille& g, int iterations) 
}
class AfficheurConsole {
    -Fichier ecriture
    +AfficheurConsole(Fichier ecriture_) 
    +void afficher(const Grille& g, int iterations) override
}
class AfficheurGraphique {
    -int windowSize;
    -sf::RenderWindow window;
    +AfficheurGraphique(int windowSize = 800)
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






class Grille {
    -int nb_lignes
    -int nb_colonnes
    -vector< vector< unique_ptr< Cellule>>> cellules
    +Grille()
    +void initialisation(const vector< vector< int>>& matrice, Regles* regle)
    +int getLignes() const
    +int getColonnes() const
    +Cellule& getCellule(int l, int c) const
    +int compterVoisinesVivantes(int l, int c) const
    +void grilleSuivante()
    +void actualiserGrille()
}
Grille o-- Cellule : "contient"
Regles .. Grille : "utilise"





class Cellule {
    -unique_ptr< Etat> etat_actuel
    -unique_ptr< Etat> etat_suivant
    -int ligne
    -int colonne
    -Grille* grille
    -Regles* regles
    +Cellule(unique_ptr< Etat> etat_initial, int l, int c, Grille* g, Regles* r)
    +void calculerEtatSuivant()
    +void actualiserEtatSuivant()
    +bool estVivante() const
    +Etat& getEtatActuel() const
    +Etat& getEtatSuivant() const
}
Cellule o-- Etat : "possède"






class Etat {
    <<abstract>>
    +virtual bool valeur() const
    +virtual unique_ptr< Etat> cloner() const
    +virtual ~Etat()
}
class EtatVivant {
    +EtatVivant()
    +bool valeur() const override
    +unique_ptr< Etat> cloner() const override
}
class EtatMort {
    +EtatMort()
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
    +RegleJDLV()
    +unique_ptr< Etat> changementEtat(const Etat& etatCourant, int nbVoisines) override
}
Regles <|-- RegleJDLV
Regles .. Cellule : "utilise"




class TestsUnitaires {
    +TestsUnitaires()
    +void testInitialisationGrille()
    +void testCompterVoisines()
    +void testEvolutionCellule()
    +void testLectureFichier()
    +void testEcritureFichier()
}


TestsUnitaires ..> Jeu : "teste"
