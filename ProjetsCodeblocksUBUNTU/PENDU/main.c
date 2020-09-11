#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"

int main(int argc, char *argv[])
{
    char lettreEntre = 0;
    int longueurChaine = 0;
    char motSecret[] = "MARRON";

    printf("Vous allez jouer au jeu du Pendu\n");
    printf("Le but du jeu est de deviner un mot\n");
    printf("Entrez une lettre est faite entrer\n");
    printf("Faites ainsi jusqu a trouver le mot\n");
    printf("Vous avez 10 coups à jouer pour reussir");


        lettreEntre = lireCaractere();    /*lireCaractere est une fonction qu'on a crée.*/
        longueurChaine = strlen(motSecret);/*La fonction strlen renvoie le nombre de caractères*/

        recherche(motSecret,lettreEntre,longueurChaine);


    return 0;
}
