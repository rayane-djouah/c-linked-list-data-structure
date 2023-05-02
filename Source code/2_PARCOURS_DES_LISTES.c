#include "headers.h"
//a. Procedure Pour afficher la note d'un participant donné
void Affiche_note()
{

    Titre("Afficher la note d'un participant");
    char another = 'y';
    char ch1[NBMAX];
    int i;
    Participant *p;

    while (another == 'y' || another == 'Y')
    {
        printf("\n\n\t Entrer le Nom du paticipant : \t");
        CouleurTexteBackg(MAGENTA,WHITE);
        scanf("%s", ch1);
        CouleurTexteBackg(BLUE,WHITE);


        strcpy(ch1, strupr(ch1)); //Eviter les erreurs de frappe.
        bool Trouv = false;
        for (i = 0; i < 7; i++)
        {
            p = formation[i];
            while ((p != NULL) && !Trouv)
            {
                if (strcmp(p->NomP, ch1) == 0) // égalité signifie que les chaines sont identiques.
                {
                    printf("\n\t\t >> La note du Participant %s %s est : << %.2f/20 >> \n", NompLLC(p), PrenomLLC(p), NoteLLC(p));
                    Trouv = true;
                }

                p = suivant(p);
            }
        }
        if (Trouv == false)
        {
            CouleurTexteBackg(31,28);
            printf("\n\t %s ne figure pas dans les listes des participants ! \n\n", ch1);
            CouleurTexteBackg(17,15);

        }

        printf("\n\n\t\t Autre participant? (Y/N)?");
        fflush(stdin);
        another = getchar();
    }
}
//==================================================================================
//b. Afficher la moyenne des participant à une formation donnée
void Moy_Part()
{
    Titre("Afficher la note moyenne des participants dans une formation donn""\x82""");
    menu_formations();
    char another = 'y';
    while (another == 'y' || another == 'Y')
    {
        int form = 0;
        int Si_nombre;
        do
        {
            printf("\n\n\t\t\t\t Entrer le numero de la formation :--> ");

            CouleurTexteBackg(MAGENTA,WHITE);
            Si_nombre = scanf("%d", &form);
            /* vider le buffer après la saisie */
            scanf ("%*[^\n]");
            getchar ();
            CouleurTexteBackg(BLUE,WHITE);

            if ((form<1)||(form>7)||(Si_nombre==0))
            {
                CouleurTexteBackg(WHITE,RED);
                printf("\n\t\t Choix Incorrect!\n");
                CouleurTexteBackg(BLUE,WHITE);

            }
        }
        while ((form < 1) || (form > 7)||(Si_nombre==0));
        form--;
        float som = 0;
        int cpt = 0;

        Participant *p;

        p = formation[form];
        while (p != NULL)
        {
            som = som + p->NoteP;
            cpt++;
            p = suivant(p);
        }

        float moy = som / cpt;
        //Déclaration des Noms des formations
        char *Nom_formation[] = {"C", "C++", "C#", "Java", "JavaScript", "Python", "PHP"};
//==================================================================================

        printf("\n\n\t>>\t La note moyenne des participants dans l'examen de la formation << %s >> est: \t (%.2f / %d) / 20  =  (%.2f)/20 \n\n", Nom_formation[form], som, cpt, moy);
        printf("\n\n\t\t Autre formation? (Y/N)?");
        fflush(stdin);
        another = getchar();
    }
    Proc_fin();
}
//==================================================================================

// c. Afficher les participants n’ayant pas réussi durant la session en cours, ordonnés par formation
void affich_P_non_reuss()
{
    Titre("les participants qui n'ont pas reussi durant la session en cours dans l'examen final de la formation");
    int i;
    Participant *p;
    int aucun = 1;

    for (i = 0; i < 7; i++)
    {
        affich_formation(i);

        p = formation[i];

        while (p != NULL)
        {
            if (NoteLLC(p) < 10)
            {
                aucun = 0;
                affich_partic(p);
            }

            p = suivant(p);
        }
        printf("\n\n");

        if (aucun == 1)
        {
            Erreur("\t Aucun Participant en cette formation.\n\n\n");
        }

        system("pause");
    }
    if (aucun == 1)
    {
        printf("\n\n");
        Erreur("ATTENTION!");
        Erreur("\t -> Aucun participant en memoire, v""\x82""rifier le fichier participant.txt et r""\x82""initialiser les listes des participants. \n");
    }


    Proc_fin();
}

//==================================================================================
