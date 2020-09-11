#include <stdio.h>
#include <stdlib.h>


int somme(int tableau[], int tailleTableau);

int main(int argc, char *argv[])
{
   int tableau[3];

    tableau[0] = 2;
    tableau[1] = 3;
    tableau[2] = 29;

    int somme(&tableau[], &tailleTableau);

    printf("La somme de ces tableaux est %d\n", somme);

    return 0;
}

int somme(int tableau[], int tailleTableau)
{
   int somme = 0;
    somme = int *tableau + int *tableau[1] + int *tableau[2];
    return int somme;
}
