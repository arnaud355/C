#include <stdio.h>
#include <stdlib.h>
#include "tableaux.h"


int sommeTableau(int tableau[], int tailletableau)
{
    int i = 0, somme = 0;
    for(i = 0; i < tailletableau; i++)
    {
        somme = somme + tableau[i];

    }
    return somme;
}

double moyenneTableau(int tableau[], int tailleTableau)
{
int moyenne = 0;
moyenne = sommeTableau(tableau, 4) / tailleTableau;

return moyenne;
}

void copie(int tableauOriginal[], int tableauCopie[], int tailleTableau)
{
int i = 0;
 tableauCopie = tableauOriginal;

for(i = 0; i < tailleTableau; i++)
{
printf("%d\n", tableauCopie[i]);
}

}

void maximumTableau(int tableau[], int tailleTableau, int valeurMax)
{
int i = 0;
for(i = 0; i < tailleTableau; i++)
{
    if(tableau[i] > valeurMax)
    {
        tableau[i] = 0;
    }
        printf("%d\n", tableau[i]);
}

}
