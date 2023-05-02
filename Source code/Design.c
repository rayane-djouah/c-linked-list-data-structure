#include "headers.h"

//  Caractères spéciaux utilisés : é : \x82  è : \x8A    à : \x85    ê : \xEA

//Procédure pour déplacer le curseur
void gotoxy(int x, int y)
{
    COORD CRD;
    CRD.X = x;
    CRD.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CRD);
}
//==================================================================================
//Procédure pour changer la couleur du texte et de l'arrière plan:
void CouleurTexteBackg(int text, int backg)
{
    WORD wColor = ((backg & 0x0F) << 4) + (text & 0x0F);;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
    return;
}
//==================================================================================
//Procédure pour écrire un caractère plusieurs fois (pour un nombre donné de fois)
void printChar(char cha[1], int n)
{
    while (n != 0)
    {
        printf(cha);
        n--;
    }
}
//==================================================================================
//Procédure pour vider l'écran d'*age et afficher le titre du programme
void TP_Titre()
{
    system("cls");
    printf("\n\n\t");
    CouleurTexteBackg(BLACK,YELLOW);
    printChar("=", 7);
    printf(" TP1 : Application de gestion des participants ""\x85"" la s""\x82""rie de formations en programmation | ** Institut de formation specialis""""\x82"""" (Formation+) ** ");
    printChar("=", 7);
    CouleurTexteBackg(BLUE,WHITE);

    printf("\n");
}
//=================================================
//Procédure pour afficher un titre
void Titre(char ch[])
{
    TP_Titre();
    printf("\n\n\t");
    CouleurTexteBackg(LIGHTBLUE,YELLOW);

    printChar("-", 19);
    printf(">\t %s \t<", ch);
    printChar("-", 19);
    CouleurTexteBackg(BLUE,WHITE);
    printf("\n\n");
}

//=================================================
// Procédure pour afficher un message erreur
void Erreur(char ch[])
{
    CouleurTexteBackg(WHITE,RED);
    printf(" %s ", ch);
    CouleurTexteBackg(BLUE,WHITE);
}
//=================================================
// Procédure pour afficher un message de réussite
void Succ(char ch[])
{
    CouleurTexteBackg(GREEN,WHITE);
    printf(" %s ", ch);
    CouleurTexteBackg(BLUE,WHITE);
}
//=================================================
// Procédure pour cloturer l'opération (la procédure) et attendre une touche pour sortir

void Proc_fin()
{

    printf("\n\n\n\t");
    printChar("*", 65);
    printf("\n\n\t");
    system("pause");
}

//=================================================
// Procédure pour écrire une ligne de séparation

void separer()
{
    printf("\n\n\t\t");
    printChar("*", 19);
    printf("\n\n");
}
//=================================================
// Procédure qui imprime le splashscreen du TP
void splashscreen(void)
{
    system("COLOR 6");
    printf("\n\n\t  ______  _____ _____ ");
    printf("\n\t |  ____|/ ____|_   _|\t Ecole Nationale");
    printf("\n\t | |__  | (___   | |  ");
    printf("\n\t |  __|  |___ |  | |  \t Sup""\x8A""rieure");
    printf("\n\t | |____ ____) |_| |_ ");
    printf("\n\t |______|_____/|_____|\t d'Informatique");
    printf("\n\n");
    Sleep(300);
    printf("\n\t\t\t\t  _______ _____    __       _      _       _____   ");
    printf("\n\t\t\t\t |__   __|  __  | /_ |  _  | |    | |     |  ____| ");
    printf("\n\t\t\t\t    | |  | |__) |  | | (_) | |    | |     | |      ");
    printf("\n\t\t\t\t    | |  |  ___/   | |     | |    | |     | |      ");
    printf("\n\t\t\t\t    | |  | |       | |  _  | |____| |____ | |____  ");
    printf("\n\t\t\t\t    |_|  |_|       |_| (_) |______|______||______| ");
    printf("\n\t\t\t\t                          Listes Lin""\x82""aires Chain""\x82""es");
    Sleep(300);
    printf("\n\n\t\t\t\t     Ann""\x82""e Universitaire 2020-2021 | Sem""\x8A""stre 2");
    Sleep(300);
    printf("\n\n\n\t\t\t> Appuyez sur [ENTREE] pour continuer...");
    getchar();
    system("cls");
}
//==================================================================================
// Procédure qui imprime la carte des informations du TP
void CarteTP()
{
    system("COLOR 03");
    printf("\n\n\t__________________________________________________________________________________________________\n");
    printf("\t|            ==============================={ BIENVENUE }==============================          |\n");
    printf("\t|                     *****  TP1 : APPLICATION DE GESTION DES PARTICIPANTS                       |\n");
    printf("\t|                                          A LA SERIE DES FORMATIONS EN PROGRAMATION *****       |\n");
    printf("\t|                                                                                                |\n");
    printf("\t|                             -> R""\x82""alis""\x82"" par:                                                    |\n");
    printf("\t|                                << Rayane Djouah  >>                                            |\n");
    printf("\t|                                << Samy Ghebbache >>                                            |\n");
    printf("\t|                                 Module  :   ALSDD                                              |\n");
    printf("\t|                              Algorithmiques et Structures des Donn""\x82""es Dynamiques               |\n");
    printf("\t|                      1 ""\x8A""re ann""\x82""e cycle pr""\x82""paratoire - Groupe 6                                 |\n");
    printf("\t|                                                                                                |\n");
    printf("\t|                             -> Sous la Supervision de: Monsieur Mourad Benmalek, PhD           |\n");
    printf("\t|                                                            Associate Professor                 |\n");
    printf("\t|                                                                                                |\n");
    printf("\t|                [ Ecole Nationale Sup""\x8A""rieure d'Informatique (ESI Ex INI) - Alger ]              |\n");
    printf("\t|            =========================================================================           |\n");
    printf("\t|________________________________________________________________________________________________|\n\n\n\t\t");
    printChar("=", 38);
    printf("\n\n\n\t\t\t       > Appuyer sur n'importe touche pour continuer...");
    getchar();
}
//==================================================================================
void merci()
{

    TP_Titre();
    CouleurTexteBackg(MAGENTA,WHITE);
    printf("\n\n\n");
    printf("\n\n\t\t\t\t\t     *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *");
    printf("\n\n\t\t\t\t\t     *                                            *");
    printf("\n\n\t\t\t\t\t     *                    MERCI !                 *");
    printf("\n\n\t\t\t\t\t     *                                            *");
    printf("\n\n\t\t\t\t\t     *                  AU REVOIR.                *");
    printf("\n\n\t\t\t\t\t     *                                            *");
    printf("\n\n\t\t\t\t\t     *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *\n\n\t\t");
    system("pause");
    return;
}
