#include "headers.h"
//Procedure Pour changer la note d'un Participant donné
void Mis_a_jour_note()
{
    Titre("Mettre a jour la note de l'examen post formation :");
    char autre='y';
    char ch1[NBMAX];
    int i;
    float note2;
    Participant *p;
    float note0;
    while ((autre=='y')||(autre=='Y'))
    {

        bool Trouv = false;

        printf("\n\n\t\t --> Entrer Le nom du participant : \t");
        CouleurTexteBackg(MAGENTA,WHITE);
        scanf("%s", ch1);
        CouleurTexteBackg(BLUE,WHITE);
        strcpy(ch1, strupr(ch1)); //Pour Eviter les erreurs de frappe
        for (i = 0; i < 7; i++)
        {
            p = formation[i];
            while ((p != NULL) && !Trouv)
            {
                if (strcmp(p->NomP, ch1) == 0)
                {
                    Trouv = true;
                    note0 = p->NoteP;
                    printf("\n\t\t --> Entrer la nouvelle note attribee a %s : \t", ch1);

                    int Si_nombre = scanf("%f", &note2);
                    /* vider le buffer après la saisie */
                    scanf ("%*[^\n]");
                    getchar ();
                    if ((note2<=20)&&(note2>=0)&&(Si_nombre == 1))
                    {
                        switch (MessageBox(NULL, TEXT("Vous voulez faire le changement ? \n Cliquer sur Oui / Non."), TEXT("Confirmation"), MB_YESNO))
                        {
                        case IDYES:
                            MessageBox(NULL, TEXT("Yes!"), TEXT("Changement fait !"), MB_OK);


                            p->NoteP = note2;
                            Succ("\n\t\t Changement effectu""\x82"" avec succ""\x8A""s! \n");
                            printf("\n\t >> La note de l'examen post-formation du participant %s %s qui ""\x82""tait << %.2f / 20 >> est devenue << %.2f / 20 >> \n", NompLLC(p), PrenomLLC(p),note0, NoteLLC(p));
                            break;

                        case IDNO:
                            MessageBox(NULL, TEXT("Changement non fait !"), TEXT("No!"), MB_OK);
                            Succ("\t\t Op""\x82""ration annul""\x82""e !");
                            break;

                        default:
                            Erreur("\t Erreur !");
                        }
                    }
                    else
                    {
                        Erreur("\t Note non valable ! ");
                    }


                }

                p = suivant(p);
            }
        }
        if (Trouv == false)
        {
            CouleurTexteBackg(WHITE,RED);
            printf("\t\t %s ne figure pas dans la liste des participants .\n", ch1); //C'est pour ca que j'ai gardé le booleen et j'ai pas utilisé break instruction.
            CouleurTexteBackg(BLUE,WHITE);

        }
        printf("\n\n\t\t Autre participant? (Y/N)?");
        fflush(stdin);
        autre = getchar();
    }
    Proc_fin();
}
//==================================================================================
//b. Gérer les demandes de changement de formation.
void transfere_participant()
{
    int i, form, form1; // form :le participant ou il trouvait ---form 1:sa nouvelle destination 'Formation'
    Participant *p, *tete, *p1, *p3, *q, *p3prec, *p3suiv, *tmp;

    char autre='y';
    while ((autre=='y')||(autre=='Y'))
    {
        bool Trouv = false;
        TP_Titre();
        Titre(" G""\x82""rer les demandes de changement de formation ");
        printf("\n\n\t Entrer le nom du participant : \t");
        char ch1[NBMAX];
        CouleurTexteBackg(MAGENTA,WHITE);
        scanf("%s", ch1);
        CouleurTexteBackg(BLUE,WHITE);
        strcpy(ch1, strupr(ch1));
        Exist_Participant(ch1, &Trouv, &p3, &p3prec, &form); // j'ai gardé l'indice de la formation pour effectuer des changements apres le transfert.
        if (Trouv == false)
        {
            CouleurTexteBackg(WHITE,RED);
            printf("\n\n\t\t %s ne figure pas dans la liste des participants! \n", ch1);
            CouleurTexteBackg(BLUE,WHITE);
        }
        else
        {
            menu_formations();
            int Si_nombre;
            do
            {

                printf("\n\t Etrer le num""\x82""ro de la formation auquelle voulez vous transf""\x82""rez %s --> ", ch1);

                Si_nombre = scanf("%d", &form1);
                /* vider le buffer après la saisie */
                scanf ("%*[^\n]");
                getchar ();

                if((form1<1)||(form1>7)||(Si_nombre != 1))
                {
                    CouleurTexteBackg(WHITE,RED);
                    printf("\n\t\t Choix Incorrect!\n");
                    CouleurTexteBackg(BLUE,WHITE);
                }
            }
            while ((form1<1)||(form1>7)||(Si_nombre != 1));
            form1--;
            //Déclaration des Noms des formations
            char *Nom_formation[] = {"C", "C++", "C#", "Java", "JavaScript", "Python", "PHP"};
            if (form == form1)
            {
                CouleurTexteBackg(GREEN,WHITE);
                printf("\n\n\t %s participe d""\x82""j""""\x85"""" ""\x85"" la formation "" %s "" ! \n", ch1, Nom_formation[form1]); // En cas d'erreur

                CouleurTexteBackg(BLUE,WHITE);
            }
            else
            {
                switch (MessageBox(NULL, TEXT("Vous voulez faire le changement? \n\t Click \"Yes\" or \"No\"."), TEXT("Confirmation du changement"), MB_YESNO))
                {
                case IDYES:
                    MessageBox(NULL, TEXT("Changement fait !"), TEXT(" Yes ! "), MB_OK);

                    p3suiv = suivant(p3);
                    // On doit Trouvez l'endroit où insérez ce nouveau participant
                    for (i = 0; i < 7; i++)
                    {
                        if (i == form1)
                        {
                            tete = formation[i]; // la tete de la lise destinataire
                            break;
                        }
                    }
                    p = tete;
                    while ((p != NULL) && (strcmp(ch1, NompLLC(p)) > 0))
                    {
                        p1 = p; // p  le suivant est p1 le précedent
                        p = suivant(p);
                    }
                    q = malloc(sizeof(Participant));
                    (q->NoteP) = NoteLLC(p3);
                    strcpy(NompLLC(q), NompLLC(p3));
                    strcpy(PrenomLLC(q), PrenomLLC(p3));
                    if ((p != tete) && (p != NULL)) // l'élement à insérer se trouve au milieu da la LLC
                    {
                        affadr(p1, q);
                        affadr(q, p);
                    }
                    else
                    {
                        if (p == tete) //l'element se trouve dans la tete
                        {
                            formation[form1] = q;
                            affadr(q, p);
                        }
                        else
                        {
                            //La queue
                            affadr(p1, q);
                            affadr(q, NULL);
                        }
                    }                          // On doit liberer la participant de son ancien formation
                    if (formation[form] == p3) //L'element se trouve dans la tete
                    {
                        tmp = p3;
                        formation[form] = suivant(p3);
                        liberer(tmp);
                        tmp = NULL;
                    }
                    else
                    {
                        if (p3 != formation[form] && p3suiv != NULL)
                        {
                            liberer(p3);
                            p3 = NULL;
                            affadr(p3prec, p3suiv);
                        }
                        else
                            affadr(p3prec, NULL);
                    }

                    CouleurTexteBackg(GREEN,WHITE);
                    printf("\n\n\t %s qui ""\x82""tait inscrit en << %s >> est transf""\x82""r""\x82"" avec succ""\x8A""s vers la formation << %s >> ! \n", ch1,Nom_formation[form], Nom_formation[form1]);
                    CouleurTexteBackg(BLUE,WHITE);
                    break;
                case IDNO:
                    MessageBox(NULL, TEXT("Changement non fait !"), TEXT("Annulation"), MB_OK);
                    CouleurTexteBackg(GREEN,WHITE);
                    printf("\n\t Opp""\x82""ration annul""\x82""e ! ");
                    CouleurTexteBackg(BLUE,WHITE);
                    break;
                default:
                    CouleurTexteBackg(WHITE,RED);
                    printf("\n\t Erreur ! ");
                    CouleurTexteBackg(BLUE,WHITE);



                }
            }

        }
        printf("\n\n\t\t Autre participant? (Y/N)?");
        fflush(stdin);
        autre = getchar();
    }
    Proc_fin();
}



//==================================================================================

// Procédure qui verifie l'existance d'un participant et donne sa formation et le pointeur vers le participant qui le précède
void Exist_Participant(char ch1[NBMAX], bool *Trouv, Participant **p, Participant **prec, int *form)
{
    int i;
    Participant *p1, *precedent;
    for (i = 0; i < 7; i++)
    {
        p1 = formation[i];
        while (((p1) != NULL) && (*Trouv == false))
        {
            if (strcmp(ch1, NompLLC(p1)) == 0)
            {
                *Trouv = true;
                *form = i;
                *p = p1;
                *prec = precedent;
            }
            else
            {
                precedent = p1;
                p1 = suivant(p1);
            }
        }
    }
}
