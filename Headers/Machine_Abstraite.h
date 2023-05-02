#ifndef MACHINE_ABSTRAITE_H_INCLUDED
#define MACHINE_ABSTRAITE_H_INCLUDED
/**********************************************************************/
/************** La machine abstraite relative aux  LLC. **************/
/********************************************************************/
//  Definir le min et le max des notes generees:
#define NBMAX 20
#define NBMIN 7

/*****************************************************************/
/************** Les Structures de données utilisées **************/
/*****************************************************************/

//==================================================================================

typedef struct Participant Participant; //Participant joue le role du maillon
////Chaque participant est représenté par un enregistrement
typedef struct Participant
{
    char NomP[30];    //en cas d'inscrire un partipant ayant un long nom ou bien prenom.
    char PrenomP[30]; //La meme raison
    float NoteP;
    Participant *suivant;
} Participant;

// Déclaration de la structure du Tableau qui contient les listes des participants.
Participant *formation[7];  //Chaque groupe de participants est représenté par une liste linéaire chaînée unidirectionnelle
//Chaque participant peut s’inscrire à une seule formation
void allouer(Participant **p);
// Procédure qui détruit le maillon pointé par p.
void liberer(Participant *p);

// Procédure qui affecte Le nom du participant dans le champ (Nom) du maillon pointé par p.
void affNom(Participant *p, char ch1[NBMAX]);

// Procédure qui affecte Le Prenom du participant dans le champ (Prenom) du maillon pointé par p.
void affPrenom(Participant *p, char ch1[NBMAX]);

// Procédure qui affecte une note aléatoire comprise entre 7 et 20 à un participant dans le champ (Note) du maillon pointé par p.
void affNote(Participant *p);
// Procédure qui affecte q dans le champ (adr) du maillon pointé par p.
void affadr(Participant *p, Participant *q);
// Fonction qui retourne le contenu du champ (Nomp) du maillon pointé par p.
char *NompLLC(Participant *p);
// Fonction qui retourne le contenu du champ (PrenomP) du maillon pointé par p.
char *PrenomLLC(Participant *p);
// Fonction qui retourne le contenu du champ (Notep) du maillon pointé par p.
float NoteLLC(Participant *p);
// Fonction qui retourne le contenu du champ (adr) du maillon pointé par p.
Participant *suivant(Participant *p);
#endif // MACHINE_ABSTRAITE_H_INCLUDED
