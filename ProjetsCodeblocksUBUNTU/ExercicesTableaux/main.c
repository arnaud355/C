#include <stdio.h>
#include <stdlib.h>
#include "tableaux.h"

int main(int argc, char *argv[])
{
    int tableau[4] = {5,46,75,16};
    int tableauOriginal[3] = {2,5,6}, tableauCopie[3] = {0};

    printf("%d\n",sommeTableau(tableau, 4));
    printf("%f\n", moyenneTableau(tableau, 4));

    copie(tableauOriginal,tableauCopie,3);
    maximumTableau(tableau, 4, 50);
    return 0;
}
