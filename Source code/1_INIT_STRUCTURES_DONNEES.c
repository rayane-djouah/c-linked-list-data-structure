#include "headers.h"
//=================================================

//Procédure pour construisez les listes des participants (par formation) à partir du fichier texte (Participants.txt).
//INITIALISATION DES STRUCTURES DE DONNÉES
void creer_LLC()
{
    ptr = NULL;
    Titre("Cr""\x82""ation des Listes des participants ""\x85"" partir du fichier ""Participants.txt"" ");
    int i = -1, test; //Pour quelle soit =0 aprés Formation: C et qu'on puisse commencer notre traitement.
    ptr = fopen("Participants.txt", "r");
    Participant *p, *tetellc, *q;
    char ch1[20], ch2[20];                        //Pour Vérifier en utilisant ch1 le cas ou ch1="Formation" afin de faire un saut de ligne et incrementer le i pour sauvegarder la tete dans le tableau formation
    while (fscanf(ptr, "%s %s", ch1, ch2) != EOF) //Déterminer la fin du fichier
    {
        allouer(&p);
        tetellc = p;
        if (strcmp(ch1, "Formation:") == 0)
        {
            i = i + 1;
            // Un traitement pour la tete du fichier ------->ch1=="Formation:" <->Au début du fichier <->ce conditionnelle sera vérifié juste une fois.
            fscanf(ptr, "%s %s", ch1, ch2);
        }
        while ((strcmp(ch1, "Formation:") != 0) && test != -1) //    tets!=-1 <-> La fin du fichier .
        {
            q = p;
            allouer(&p); // On est obligé d'utiliser 2 boucle car a chaque fin de boucle  on crée les participants d'une formation X
            affNom(q, ch1);
            affPrenom(q, ch2);
            affadr(q, p);
            affNote(q);
            test = fscanf(ptr, "%s %s", ch1, ch2);
        }
        affadr(q, NULL);
        liberer(p); // le dernier maillon qui a été cree sera vide<->inutile<->Gagner de l'espace memoire.
        formation[i] = tetellc;
        i++;
    }
    Succ("\n\t ** Les listes des participants sont initialis""\x82""es avec succ""""\x8A""""s! ** \n");
    Proc_fin();
}
