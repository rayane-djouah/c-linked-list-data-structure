#ifndef AFFICHAGE_DONNES_H_INCLUDED
#define AFFICHAGE_DONNES_H_INCLUDED
// Procédure pour afficher le nom d'une formation donnée par son n° i au format d'un titre
void affich_formation(int i);
//==================================================================================
//Procédure pour afficher les details d'un participant à partir de son enregistrement (Nom, Prenom, Note)
void affich_partic(Participant *p);
//==================================================================================
//Procédure pour afficher les listes des participants
void afficher_LP();
// Procédure qui affiche les formations disponibles
void menu_formations();
#endif // AFFICHAGE_DONNES_H_INCLUDED
