#ifndef INS_SUPP_MIS_H_INCLUDED
#define INS_SUPP_MIS_H_INCLUDED

// a. Procedure Pour changer la note d'un Participant donn�
void Mis_a_jour_note();
//==================================================================================

// Proc�dure qui verifie l'existance d'un participant et donne sa formation et le pointeur vers le participant qui le pr�c�de
void Exist_Participant(char ch1[NBMAX], bool *Trouv, Participant **p, Participant **prec, int *form);

//==================================================================================
//b. G�rer les demandes de changement de formation.
void transfere_participant();

#endif // 3_INSERTION-SUPPRESSION-MIS__A_JOUR_DELEMENTS_H_INCLUDED
