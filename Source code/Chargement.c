#include "headers.h"
//==================================================================================
// Procédure pour verifier l'existence du fichier "Participants.txt" et avertir l'utilisateur au cas contraire
void Loading()
{
    system("cls");

    gotoxy(10, 3);
    system("COLOR 01");
    printf("<<<< Loading Please Wait - Chargement du fichier ""participants.txt"" du m""\x65""me r""\x82""p""\x8A""rtoire >>>> ");
    for (int i = 0; i < 5; i++)
    {
        printf("\t* * *");
        Sleep(500);
    }
    FILE *fp;
    if ((fp = fopen("Participants.txt", "rb+")) == NULL)
    {
        TP_Titre();
        Erreur("\n\n\t Erreur lors de l'ouverture du fichier <<Participants.txt>> \n\n");
        Erreur("\t=> V""\x82""rifiez que le fichier est dans le m\xEAme r""\x82""p""\x8A""rtoire avec le programme \n\n\n\n");
        printf("\n\n\n\n\n\t\t\t\t\t> Press any key to exit...... ");
        getchar();
    }
    else
    {
        system("COLOR F2");
        printf("\n\n\n");
        printf("\n\n\t\t\t\t\t     *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *");
        printf("\n\n\t\t\t\t\t     *                                            *");
        printf("\n\n\t\t\t\t\t     *                    Welcome !               *");
        printf("\n\n\t\t\t\t\t     *                                            *");
        printf("\n\n\t\t\t\t\t     *   <<Participants.txt>> charg""\x82"" avec succ""\x8A""s! *");
        printf("\n\n\t\t\t\t\t     *                                            *");
        printf("\n\n\t\t\t\t\t     *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *\n\t\t");
        system("pause");
        creer_LLC();
        TP_Titre();
        TP_Menu();
    }
}
//==================================================================================

// Procédure pour afficher le menu des opérations possibles, demander le choix de l'utilisateur et fait appel au procédure pertinente
void TP_Menu()
{
    while (1)
    {
        TP_Titre();
        printf("\n\t");
        printChar("*", 64);
        printf("\n\n\t\t\t\t 1. R""\x82""initialiser les listes des participants ""\x85"" partir du fichier Participants.txt");
        printf("\n\n\t\t\t\t 2. Afficher les listes des participants");
        printf("\n\n\t\t\t\t 3. Afficher la note de l'examen post-formation d'un participant");
        printf("\n\n\t\t\t\t 4. Afficher la note moyenne des participants dans une formation donn""""\x82""""e");
        printf("\n\n\t\t\t\t 5. Afficher les participants qui n'ont pas r""\x82""ussi ""\x85"" l'examen post-formation");
        printf("\n\n\t\t\t\t 6. Changer la formation pour un partipant donn""\x82""");
        printf("\n\n\t\t\t\t 7. Modifier la note de l'examen post-formation pour un participant donn""\x82""");
        printf("\n\n\t\t\t\t 8. Trier et afficher la liste des participants par ordre de m""\x82""rite dans une formation donn""\x82""e ");
        printf("\n\n\t\t\t\t 9. Sauvegarder les r""\x82""sultats dans un fichier .txt");
        printf("\n\n\t\t\t\t 10. Quitter le programme\n\n\t");
        printChar("*", 64);
        printf("\n\n\t\t\t\t Entrer votre choix :--> ");
        int option;
        CouleurTexteBackg(MAGENTA,WHITE);

        scanf("%d", &option);

        CouleurTexteBackg(BLUE,WHITE);
        switch (option)
        {
        case 1:
            creer_LLC();
            break;
        case 2:
            afficher_LP();
            break;
        case 3:
            Affiche_note();
            break;
        case 4:
            Moy_Part();
            break;
        case 5:
            affich_P_non_reuss();
            break;
        case 6:
            transfere_participant();
            break;
        case 7:
            Mis_a_jour_note();
            break;
        case 8:
            ordre_de_mertite();
            break;
        case 9:
            sauvegarder();
            break;
        case 10:
            switch (MessageBox(NULL, TEXT("Vous voulez quitter? \n Veuillez enregistrer avant de quitter."), TEXT("Confirmation"), MB_YESNO))
            {
            case IDYES:
                merci();
                return;
                break;
            case IDNO:
                MessageBox(NULL, TEXT("Continuer vos modifications ensuite enregistrer."), TEXT("No"), MB_OK);
                break;
            default:
                Erreur("Erreur !");
            }
            break;
        default:
            printf("\n\t\t Choix incorrect ! ");
            printf("\n\t\t Appuyer sur n'importe touche...\n\n\n");
            getchar();
            system("pause");
        }
    }
}
