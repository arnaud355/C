#include <stdio.h>
#include <stdlib.h>

int Piscine (int Largeur, int Hauteur, int Longeur)
{
    int VolumePiscine = 0;
    VolumePiscine = Largeur * Hauteur * Longeur;
    return VolumePiscine;
}
int main(int argc, char *argv[])
{


   printf("Piscine Cesson a un volume de %dm cube\n", Piscine(25, 3, 50));
    return 0;
}
