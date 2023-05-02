#ifndef DESIGN_H_INCLUDED
#define DESIGN_H_INCLUDED

//Proc�dure pour d�placer le curseur
void gotoxy(int x, int y);
//==================================================================================
//Proc�dure pour changer la couleur du texte et de l'arri�re plan:
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
//Proc�dure pour �crire un caract�re plusieurs fois (pour un nombre donn� de fois)
void printChar(char cha[1], int n);
//==================================================================================
//Proc�dure pour vider l'�cran d'*age et afficher le titre du programme
void TP_Titre();
//=================================================
//Proc�dure pour afficher un titre
void Titre(char ch[]);

//=================================================
// Proc�dure pour afficher un message erreur
void Erreur(char ch[]);
//=================================================
// Proc�dure pour afficher un message de r�ussite
void Succ(char ch[]);
//=================================================
// Proc�dure pour cloturer l'op�ration (la proc�dure) et attendre une touche pour sortir

void Proc_fin();

//=================================================
// Proc�dure pour �crire une ligne de s�paration

void separer();

//=================================================
// Proc�dure qui imprime le splashscreen du TP
void splashscreen(void);
//==================================================================================
// Proc�dure qui imprime la carte des informations du TP
void CarteTP();
//==================================================================================
void merci();
#endif // DESIGN_H_INCLUDED
