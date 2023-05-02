//==================================================================================
//----------------------Tri_Par_fusion-------------------------
//Ce tri me permet de
//Complexity O(n*log(n))
//Gagner la permutation de Note,Prénom,Nom ,surtout dans le cas des tableaux(Les noms et prénoms) dans chaque traitement fait,aussi une variable  et un Tableau de chaine de permutation.(Trés couteux)
 //=============================================================================

Participant* interclasser_Noms(Participant* L1,Participant* L2)
{ Participant *L3,*P;
    if  ( strcmp(NompLLC(L1),NompLLC(L2)) < 0)
       {
           L3=L1;
           L1=suivant(L1);
       }                                                            //Interclassemnt par ordre alphabétique.
    else
     {
         L3=L2;
         L2=suivant(L2);
     }
   P=L3;
   while (L1!=NULL && L2!=NULL)
    {
    if (strcmp(NompLLC(L1),NompLLC(L2)) < 0)
    {
        affadr(P,L1);
        P=L1;
        L1=suivant(L1);
    }
    else
    {
        affadr(P,L2);
        P=L2;
        L2=suivant(L2);
    }
   }
   if (L1!=NULL)  affadr(P,L1);
   else
    if (L2!=NULL) affadr(P,L2);

   return L3;
}
Participant* interclasser_Notes(Participant* L1,Participant* L2)
{ Participant *L3,*P;
    if (NoteLLC(L1) > NoteLLC(L2) )
       {
           L3=L1;
           L1=suivant(L1);             //Interclassement par Note
       }
    else
     {
         L3=L2;
         L2=suivant(L2);
     }
   P=L3;
   while (L1!=NULL && L2!=NULL)
    {
    if (NoteLLC(L1) > NoteLLC(L2))
    {
        affadr(P,L1);
        P=L1;
        L1=suivant(L1);
    }
    else
    {
        affadr(P,L2);
        P=L2;
        L2=suivant(L2);
    }
   }
   if (L1!=NULL)  affadr(P,L1);
   else
    if (L2!=NULL) affadr(P,L2);

   return L3;
}
void milieu(Participant* tete,Participant** gauche,Participant** droite)
{
	Participant *fast;
	Participant *slow;
	slow = tete;
	fast = suivant(tete);
	while (fast != NULL)
        {
		fast = suivant(fast);
		if (fast != NULL)
            {
			slow = suivant(slow);
			fast = suivant(fast);

		}
	}
	*gauche=tete;
	*droite=suivant(slow);
	affadr(slow,NULL);
    // Pour obtenir deux sous LLC
}
Participant* Tri_fusion_NOTE(Participant* tete)    //Trier Par ordre de mérite.
 { Participant *head1,*head2,*gauche,*droite;

     if (tete==NULL || suivant(tete)==NULL) return tete;
     else
     {
         milieu(tete,&gauche,&droite);
         head1=Tri_fusion_NOTE(gauche);
         head2=Tri_fusion_NOTE(droite);
         return(interclasser_Notes(head1,head2));
     }
 }
 Participant* Tri_fusion_NOM(Participant* tete)  //Trier par ordre alphabétique.
 { Participant *head1,*head2,*gauche,*droite;

     if (tete==NULL || suivant(tete)==NULL) return tete;
     else
     {
         milieu(tete,&gauche,&droite);
         head1=Tri_fusion_NOM(gauche);
         head2=Tri_fusion_NOM(droite);
         return(interclasser_Noms(head1,head2));
     }
 }

 //=============================================================================

void ordre_de_mertite()
{Participant *p;
 int i;
    char autre='y';
    while ((autre=='y')||(autre=='Y'))
    {

        TP_Titre();
        Titre("Affichage par ordre de merite");
        menu_formations();

        int form = 0;
        do
        {
            printf("\n\n\t\t\t\t Donner le numero de la formation :--> ");
            scanf("%d", &form);
            if ((form<1)||(form>7))
            {
                CouleurTexteBackg(WHITE,RED);
                printf("\n\t\t Choix Incorrect!\n");
                CouleurTexteBackg(BLUE,WHITE);

            }
        }
        while ((form < 1) || (form > 7));
        form--;
        printf("\n\n");
        Titre("Affichage par ordre de merite pour chaque Formation");

        affich_formation(form);

        //on récupére la tete de la formation
        p=formation[form];
        formation[form]=Tri_fusion_NOTE(p);
        p=formation[form];
        while (p != NULL)
        {
            affich_partic(p);
            p = suivant(p);
        }
        printf("\n\n\t\t Autre Formation voulez l'affichez? (Y/N)?");
        fflush(stdin);
        autre = getchar();
        //on doit gardrer l'ordre alphabétique  //
        for (i=0;i<7;i++)
        {
            formation[i]=Tri_fusion_NOM(formation[i]);
        }
    }
    Proc_fin();
}

//==================================================================================
