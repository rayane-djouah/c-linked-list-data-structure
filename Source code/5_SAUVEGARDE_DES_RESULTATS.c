#include "headers.h"

//Procedure Pour enregistrer les modifications apportées aux listes.
void sauvegarder()
{
    Titre("Sauvegarde des resultats ... ");
    int i;
    Participant *p;
    FILE *pf;
    pf = fopen("Resultats.txt", "w");
    for (i = 0; i < 7; i++)
    {
        p = formation[i];
        //Déclaration des Noms des formations
        char *Nom_formation[] = {"C", "C++", "C#", "Java", "JavaScript", "Python", "PHP"};
//==================================================================================

        fprintf(pf, "Formation: %s \n", Nom_formation[i]);
        while (p != NULL)
        {
            fprintf(pf, "%s  %s %.2f\n", NompLLC(p), PrenomLLC(p), NoteLLC(p));
            p = suivant(p);
        }
    }
    fclose(pf);

    Succ("\n\t ** Les listes des participants sont sauvegard""\x82""es avec succ""\x8A""s ! \n");

    Succ("\t un fichier "" Resultats.txt "" est cr""\x82""e dans le m""\x65""me r""\x82""p""\x8A""rtoire du programme ** \n");
    Proc_fin();
}
