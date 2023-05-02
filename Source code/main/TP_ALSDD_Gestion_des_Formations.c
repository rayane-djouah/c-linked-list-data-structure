///////////////////////////////////////////////////////////
//          ******* TP NUMERO 1 ALSDD LLC  *******      //
//            << REALISE PAR: >>                       //
//             ** RAYANE DJOUAH **                    //
//              ** GHEBBACHE SAMY **                 //
//           - 1CPI GROUPE 06  -                   //
//   [ Ecole Nationale Superieure d'Informatique  //
//       (ESI Ex INI) - Alger - Algerie ]       //
//////////////////////////////////////////////////

#include "Headers.h"
//==================================================================================
/**************************************************/
/************** Programme Principal **************/
/************************************************/
int main()
{
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE); // Pour agrandir la taille de la fenètre
    SetConsoleTitle("TP1 : Application de gestion des participants ""\x85"" la s""\x82""rie de formations en programmation"); // Pour afficher le titre de la fenètre
    splashscreen();
    CarteTP();
    Loading();
    return 0;
}
