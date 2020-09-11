#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main(int argc, char *argv[])
{
    Personnes joueurs[2];/*On creer une variable de type Personnes, qui contiendra
    les sous-variables de Personnes, pour y accéder: variable.NomDeLaComposante*/
    int i = 0;

    for(i = 0; i < 2; i++){
        printf("Quel est votre prenom?");
        scanf("%s",joueurs[i].prenom);
        printf("Quel est votre score?");
        scanf("%d",&joueurs[i].score);
    }

    for(i = 0; i < 2; i++){
        printf("joueur %s votre score est %d\n",joueurs[i].prenom,joueurs[i].score);

    }
    return 0;
}
