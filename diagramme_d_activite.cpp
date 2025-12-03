//
// Created by tarek on 02/12/2025.
//*
flowchart TB
 subgraph InterfacesLayer["Interfaces"]
        I_start(["Début utilisateur"])
        I_chooseMode@{ label: "Choisir le mode d'affichage (Console ou Graphique)" }
        I_run(["Exécuter le programme (main.cpp + Terminal)"])
        I_chooseParams@{ label: "Choisir les paramètres du jeu (nb itérations, tempo, fichier d'entrée)" }
        I_end(["Fin utilisateur"])
  end
 subgraph ServicesLayer["Services :"]
        S_mainLit(["main.cpp lit le mode et les paramètres"])
        S_creeJeu@{ label: "Instancie l'objet Jeu" }
        S_creeRegles(["Instancie Regles / RegleDLV"])
        S_creeGrille(["Instancie Grille"])
        S_initJeu0(["Jeu initialise t = 0 (lecture du fichier)"])
        S_lancer(["Jeu.lancerSimulation()"])
        S_iterLoop@{ label: "Pour chaque itération t = 1 à n jusqu'à stabilité" }
        S_testContinue{"Dernière itération ou état stable ?"}
  end

 subgraph ComposantsLayer["Composants :"]
        C_initCells(["Grille.initialisation()(création des Cellule)"])
        C_initEtat(["Chaque Cellule crée un unique_ptr EtatVivant ou EtatMort selon le fichier"])
        C_calcSuivLoop[["Pour chaque Cellule : calculerEtatSuivant()"]]
        C_regles(["Regles.calculerEtatSuivant() (RegleDLV utilise la Grille)"])
        C_compteVois(["Grille.compterVoisinsVivants(cellule)"])
        C_etatSuiv(["Déterminer etat_suivant (EtatVivant ou EtatMort)"])
        C_actuGrille(["Grille.actualiserGrille() (etat_actuel = etat_suivant)"])
        C_modeAff{"Mode Console ou Graphique ?"}
        C_affConsole(["AfficheurConsole.afficher(Grille)"])
        C_affGraph(["AfficheurGraphique.afficher(Grille)"])
  end
    I_start --> I_run
    I_run --> I_chooseParams
    I_chooseParams --> I_chooseMode
    S_mainLit --> S_creeJeu
    I_chooseMode --> S_mainLit
    S_creeJeu --> S_creeRegles
    S_creeRegles --> S_creeGrille
    S_creeGrille --> S_initJeu0
    S_initJeu0 --> C_initCells
    C_initCells --> C_initEtat
    C_initEtat --> S_lancer
    S_lancer --> S_iterLoop
    S_iterLoop --> C_calcSuivLoop
    C_calcSuivLoop --> C_regles & C_actuGrille
    C_regles --> C_compteVois & C_etatSuiv
    C_compteVois --> C_regles
    C_etatSuiv --> C_calcSuivLoop
    C_actuGrille --> C_modeAff
    C_modeAff -- Console --> C_affConsole
    C_affConsole --> S_testContinue
    C_modeAff -- Graphique --> C_affGraph
    C_affGraph --> S_testContinue
    S_testContinue -- Non --> S_iterLoop
    S_testContinue -- Oui --> I_end

    I_chooseMode@{ shape: stadium}
    I_chooseParams@{ shape: stadium}
    S_creeJeu@{ shape: stadium}
    S_iterLoop@{ shape: subroutine}