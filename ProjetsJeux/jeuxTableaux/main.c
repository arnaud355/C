#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"
#define bool char
#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[])
{
    int tab[4] = {15,81,22,13};
    int tabOrigine[4] = {7,9,10,11};
    int tabCopie[4] = {0};
    int tabDesordre[5] = {2014,2001,98,99,95};
    int somme = 0, i = 0;
    double moyenne = 0;

    somme = sommeTableau(tab,4);
    printf("%d\n", somme);

    moyenne = moyenneTableau(tab,4);
    printf("%f\n", moyenne);

    copie(tabOrigine,tabCopie,4);

      for(i = 0; i < 4; i++){
        printf("%d",tabCopie[i]);
    }

    maximumTableau(tab,4,15);

      for(i = 0; i < 4; i++){
        printf("%d\n",tab[i]);
    }
    ordonnerTableau(tabDesordre,5);

     for(i = 0; i < 5; i++){
            printf("%d\n",tabDesordre[i]);
        }
    return 0;
}
