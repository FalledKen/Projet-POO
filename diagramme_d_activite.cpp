//
// Created by tarek on 02/12/2025.
//*
flowchart TB
 subgraph U["Utilisateur"]
        U_start(["Début"])
        U_choose@{ label: "Choisir fichier de configuration et mode d'affichage" }
U_startSim("Demander le démarrage de la simulation")
U_end(["Fin"])
end
subgraph S["Service : Jeu"]
S_init("initialiserDepuisFichier(chemin)")
S_setAff("definirAfficheur(IAfficheur)")
S_lancer("lancer()")
S_checkCond{"Stable ou bien les n itérations sont au max ?"}
S_etape("etape()")
end
subgraph C["Composants : Grille / Règle / Afficheur / Cellule"]
C_load("Grille.chargerDepuisFichier(chemin)")
C_calcLoop("Pour chaque cellule : calculÉtatSuivant (Regle + Grille)")
C_applyLoop("Pour chaque cellule : AppliquerEtatSuivant()")
C_afficher("Afficheur.afficher(Grille)")
end
U_start --> U_choose
U_choose --> S_init
S_init --> C_load
C_load --> S_setAff
S_setAff --> U_startSim
U_startSim --> S_lancer
S_lancer --> S_checkCond
S_checkCond -- Non --> S_etape
S_etape --> C_calcLoop
C_calcLoop --> C_applyLoop
C_applyLoop --> C_afficher
C_afficher --> S_checkCond
S_checkCond -- Oui --> U_end

U_choose@{ shape: rounded}