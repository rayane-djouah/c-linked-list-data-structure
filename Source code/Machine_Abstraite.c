#include "headers.h"
void allouer(Participant **p)
{
    *p = malloc(sizeof(Participant));
}
// Proc�dure qui d�truit le maillon point� par p.
void liberer(Participant *p)
{
    free(p);
}
// Proc�dure qui affecte Le nom du participant dans le champ (Nom) du maillon point� par p.
void affNom(Participant *p, char ch1[NBMAX])
{
    strcpy(p->NomP, ch1);
}
// Proc�dure qui affecte Le Prenom du participant dans le champ (Prenom) du maillon point� par p.
void affPrenom(Participant *p, char ch1[NBMAX])
{
    strcpy(p->PrenomP, ch1);
}
// Proc�dure qui affecte une note al�atoire comprise entre 7 et 20 � un participant dans le champ (Note) du maillon point� par p.
void affNote(Participant *p)
{
    float n,n1;
    n1=(rand()%(NBMIN-NBMAX)+NBMIN);
    n1=(n1)/100;
    n=(rand()%(NBMIN-NBMAX)+NBMIN)+n1;
    p->NoteP = n;
}
// Proc�dure qui affecte q dans le champ (adr) du maillon point� par p.
void affadr(Participant *p, Participant *q)
{
    p->suivant = q; // (p->adr) est l'�quivalent de (*p.adr)
}
// Fonction qui retourne le contenu du champ (Nomp) du maillon point� par p.
char *NompLLC(Participant *p)
{
    return (p->NomP);
}
// Fonction qui retourne le contenu du champ (PrenomP) du maillon point� par p.
char *PrenomLLC(Participant *p)
{
    return (p->PrenomP);
}
// Fonction qui retourne le contenu du champ (Notep) du maillon point� par p.
float NoteLLC(Participant *p)
{
    return (p->NoteP);
}

// Fonction qui retourne le contenu du champ (adr) du maillon point� par p.
Participant *suivant(Participant *p)
{
    return p->suivant;
}
