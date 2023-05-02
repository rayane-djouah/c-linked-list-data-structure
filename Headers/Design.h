#ifndef DESIGN_H_INCLUDED
#define DESIGN_H_INCLUDED

//Procédure pour déplacer le curseur
void gotoxy(int x, int y);
//==================================================================================
//Procédure pour changer la couleur du texte et de l'arrière plan:
#define BLACK			0
#define BLUE			1
#define GREEN			2
#define CYAN			3
#define RED				4
#define MAGENTA			5
#define BROWN			6
#define LIGHTGRAY		7
#define DARKGRAY		8
#define LIGHTBLUE		9
#define LIGHTGREEN		10
#define LIGHTCYAN		11
#define LIGHTRED		12
#define LIGHTMAGENTA	13
#define YELLOW			14
#define WHITE			15
void CouleurTexteBackg(int text, int backg);
//==================================================================================
//Procédure pour écrire un caractère plusieurs fois (pour un nombre donné de fois)
void printChar(char cha[1], int n);
//==================================================================================
//Procédure pour vider l'écran d'*age et afficher le titre du programme
void TP_Titre();
//=================================================
//Procédure pour afficher un titre
void Titre(char ch[]);

//=================================================
// Procédure pour afficher un message erreur
void Erreur(char ch[]);
//=================================================
// Procédure pour afficher un message de réussite
void Succ(char ch[]);
//=================================================
// Procédure pour cloturer l'opération (la procédure) et attendre une touche pour sortir

void Proc_fin();

//=================================================
// Procédure pour écrire une ligne de séparation

void separer();

//=================================================
// Procédure qui imprime le splashscreen du TP
void splashscreen(void);
//==================================================================================
// Procédure qui imprime la carte des informations du TP
void CarteTP();
//==================================================================================
void merci();
#endif // DESIGN_H_INCLUDED
