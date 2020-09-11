#include <stdio.h>
#include <stdlib.h>
                                                               //Rappel: nombre entier pour printf type int= %d, pour décimal typedouble= %f,
int triple(int nombre)
{
    return 3 * nombre;                                          //  pour scanf de type int= %d, pour decimal donc type double= %lf
}

int main(int argc, char *argv[])
{
    int NombreEntre = 0, NombreTriple = 0;

    printf("Entrez un nombre\n");
    scanf("%d", &NombreEntre);

    NombreTriple = triple(NombreEntre);
    printf("Le triple de ce nombre est %d\n", NombreTriple);

    return 0;
}
