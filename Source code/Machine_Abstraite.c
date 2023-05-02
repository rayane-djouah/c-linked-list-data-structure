#include "headers.h"
void allouer(Participant **p)
{
    *p = malloc(sizeof(Participant));
}
// Procédure qui détruit le maillon pointé par p.
void liberer(Participant *p)
{
    free(p);
}
// Procédure qui affecte Le nom du participant dans le champ (Nom) du maillon pointé par p.
void affNom(Participant *p, char ch1[NBMAX])
{
    strcpy(p->NomP, ch1);
}
// Procédure qui affecte Le Prenom du participant dans le champ (Prenom) du maillon pointé par p.
void affPrenom(Participant *p, char ch1[NBMAX])
{
    strcpy(p->PrenomP, ch1);
}
// Procédure qui affecte une note aléatoire comprise entre 7 et 20 à un participant dans le champ (Note) du maillon pointé par p.
void affNote(Participant *p)
{
    float n,n1;
    n1=(rand()%(NBMIN-NBMAX)+NBMIN);
    n1=(n1)/100;
    n=(rand()%(NBMIN-NBMAX)+NBMIN)+n1;
    p->NoteP = n;
}
// Procédure qui affecte q dans le champ (adr) du maillon pointé par p.
void affadr(Participant *p, Participant *q)
{
    p->suivant = q; // (p->adr) est l'équivalent de (*p.adr)
}
// Fonction qui retourne le contenu du champ (Nomp) du maillon pointé par p.
char *NompLLC(Participant *p)
{
    return (p->NomP);
}
// Fonction qui retourne le contenu du champ (PrenomP) du maillon pointé par p.
char *PrenomLLC(Participant *p)
{
    return (p->PrenomP);
}
// Fonction qui retourne le contenu du champ (Notep) du maillon pointé par p.
float NoteLLC(Participant *p)
{
    return (p->NoteP);
}

// Fonction qui retourne le contenu du champ (adr) du maillon pointé par p.
Participant *suivant(Participant *p)
{
    return p->suivant;
}
