#include "headers.h"
//==================================================================================

// Procédure pour afficher le nom d'une formation donnée par son n° i au format d'un titre
void affich_formation(int i)
{
    printf("\n\t\t");


    CouleurTexteBackg(MAGENTA,WHITE);
    printChar("-", 19);

    //Déclaration des Noms des formations
    char* Nom_formation[] = {"C", "C++", "C#", "Java", "JavaScript", "Python", "PHP"};
//=================================================

    printf(">\t Formation : %s \t<", Nom_formation[i]);

    printChar("-", 19);
    CouleurTexteBackg(BLUE,WHITE);

    printf("\n");
}
//==================================================================================
//Procédure pour afficher les details d'un participant à partir de son enregistrement (Nom, Prenom, Note)
void affich_partic(Participant *p)
{
    printf("\t Nom: %.30s ", NompLLC(p));
    printChar(" ", 30 - strlen(NompLLC(p)));

    printf("\t Pr""\x82""nom: %.30s ", PrenomLLC(p));
    printChar(" ", 30 - strlen(PrenomLLC(p)));
    if (NoteLLC(p)>=10)
    {

        CouleurTexteBackg(MAGENTA,WHITE);


        printf(" -> Note: << %.2f / 20 >>\n", NoteLLC(p));
        CouleurTexteBackg(BLUE,WHITE);
    }
    else
    {
        CouleurTexteBackg(RED,WHITE);


        printf(" -> Note: << %.2f / 20 >>\n", NoteLLC(p));
        CouleurTexteBackg(BLUE,WHITE);
    }

}
//==================================================================================
//Procédure pour afficher les listes des participants
void afficher_LP()
{
    Titre("Listes des participants");

    int i;
    Participant *p;

    int aucun = 1;

    for (i = 0; i < 7; i++)
    {
        affich_formation(i);

        p = formation[i];
        if (p != NULL)
        {

            while (p != NULL)
            {
                aucun = 0;
                affich_partic(p);

                p = suivant(p);
            }
            printf("\n\n");
        }
        else
        {
            printf("\t Aucun Participant en cette formation.\n\n\n");
        }
        system("pause");
    }
    separer();

    if (aucun == 1)
    {
        printf("\n\n\t\t");
        printChar("-", 19);
        Erreur(">\t ATTENTION! \t<");
        printChar("-", 19);
        printf("\n\n");
        Erreur("\t -> Aucun participant en memoire, v""\x82""rifier le fichier participants.txt et r""\x82""initialiser les listes des participants.");
    }


    Proc_fin();
}
// Procédure qui affiche les formations disponibles
void menu_formations()
{
    printf("\n\t");
    printChar("*", 64);
    printf("\n\n\t\t\t\t 1. C");
    printf("\n\n\t\t\t\t 2. C++");
    printf("\n\n\t\t\t\t 3. C#");
    printf("\n\n\t\t\t\t 4. Java");
    printf("\n\n\t\t\t\t 5. JavaScript");
    printf("\n\n\t\t\t\t 6. Python");
    printf("\n\n\t\t\t\t 7. PHP \n\n");
    printChar("*", 64);
}
//==================================================================================
