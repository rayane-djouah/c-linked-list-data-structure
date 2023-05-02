#ifndef MACHINE_ABSTRAITE_H_INCLUDED
#define MACHINE_ABSTRAITE_H_INCLUDED
/**********************************************************************/
/************** La machine abstraite relative aux  LLC. **************/
/********************************************************************/
//  Definir le min et le max des notes generees:
#define NBMAX 20
#define NBMIN 7

/*****************************************************************/
/************** Les Structures de donn�es utilis�es **************/
/*****************************************************************/

//==================================================================================

typedef struct Participant Participant; //Participant joue le role du maillon
////Chaque participant est repr�sent� par un enregistrement
typedef struct Participant
{
    char NomP[30];    //en cas d'inscrire un partipant ayant un long nom ou bien prenom.
    char PrenomP[30]; //La meme raison
    float NoteP;
    Participant *suivant;
} Participant;

// D�claration de la structure du Tableau qui contient les listes des participants.
Participant *formation[7];  //Chaque groupe de participants est repr�sent� par une liste lin�aire cha�n�e unidirectionnelle
//Chaque participant peut s�inscrire � une seule formation
void allouer(Participant **p);
// Proc�dure qui d�truit le maillon point� par p.
void liberer(Participant *p);

// Proc�dure qui affecte Le nom du participant dans le champ (Nom) du maillon point� par p.
void affNom(Participant *p, char ch1[NBMAX]);

// Proc�dure qui affecte Le Prenom du participant dans le champ (Prenom) du maillon point� par p.
void affPrenom(Participant *p, char ch1[NBMAX]);

// Proc�dure qui affecte une note al�atoire comprise entre 7 et 20 � un participant dans le champ (Note) du maillon point� par p.
void affNote(Participant *p);
// Proc�dure qui affecte q dans le champ (adr) du maillon point� par p.
void affadr(Participant *p, Participant *q);
// Fonction qui retourne le contenu du champ (Nomp) du maillon point� par p.
char *NompLLC(Participant *p);
// Fonction qui retourne le contenu du champ (PrenomP) du maillon point� par p.
char *PrenomLLC(Participant *p);
// Fonction qui retourne le contenu du champ (Notep) du maillon point� par p.
float NoteLLC(Participant *p);
// Fonction qui retourne le contenu du champ (adr) du maillon point� par p.
Participant *suivant(Participant *p);
#endif // MACHINE_ABSTRAITE_H_INCLUDED
