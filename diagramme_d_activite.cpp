flowchart TB
I_start(["Début utilisateur"]) --> I_run(["Exécuter le programme (main.cpp + Terminal)"])
I_run --> I_chooseParams@{ label: "Choisir les paramètres du jeu (nb itérations, tempo, fichier d'entrée)" }
I_chooseParams --> I_chooseMode@{ label: "Choisir le mode d'affichage (Console ou Graphique)" }
I_chooseMode --> S_mainLit(["main.cpp lit le mode et les paramètres"])
S_initJeu0(["Jeu initialise t = 0 (lecture du fichier)"]) --> C_initCells(["Grille.initialisation()(création des Cellule)"])
C_initCells --> C_initEtat(["Chaque Cellule crée un unique_ptr EtatVivant ou EtatMort selon le fichier"])
C_initEtat --> S_lancer(["Jeu.lancerSimulation()"])
S_lancer --> C_modeAff{"Mode Console ou Graphique ?"}
S_iterLoop@{ label: "Pour chaque itération t = 1 à n jusqu'à stabilité" } --> C_calcSuivLoop[["Pour chaque Cellule : calculerEtatSuivant()"]]
C_calcSuivLoop --> C_actuGrille(["Grille.actualiserGrille() (etat_actuel = etat_suivant)"])
C_modeAff -- Console --> C_affConsole(["AfficheurConsole.afficher(Grille)"])
C_affConsole --> n2["Écris sur le fichier"]
C_modeAff -- Graphique --> C_affGraph(["AfficheurGraphique.afficher(Grille)"])
C_affGraph --> n1["Manipulation de la vitesse"]
S_testContinue{"Dernière itération ou état stable ?"} -- Non --> S_iterLoop
S_testContinue -- Oui --> I_end(["Fin utilisateur"])
S_mainLit --> S_initJeu0
C_actuGrille --> S_testContinue
n2 --> S_iterLoop
n1 --> S_iterLoop

I_chooseParams@{ shape: stadium}
I_chooseMode@{ shape: stadium}
S_iterLoop@{ shape: subroutine}