#ifndef AFFICHAGE_DONNES_H_INCLUDED
#define AFFICHAGE_DONNES_H_INCLUDED
// Proc�dure pour afficher le nom d'une formation donn�e par son n� i au format d'un titre
void affich_formation(int i);
//==================================================================================
//Proc�dure pour afficher les details d'un participant � partir de son enregistrement (Nom, Prenom, Note)
void affich_partic(Participant *p);
//==================================================================================
//Proc�dure pour afficher les listes des participants
void afficher_LP();
// Proc�dure qui affiche les formations disponibles
void menu_formations();
#endif // AFFICHAGE_DONNES_H_INCLUDED
