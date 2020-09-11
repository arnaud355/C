#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int copiecolle(int a, int b);

int main(int argc, char *argv[])
{
    char chaine[] = "Texte", copie[80] = {0};

    strcpy(copie, chaine);                     /*L'ordre dans les parametres de la fonction est fondamental.
                                                dans ce cas on dit: copie est égal à ce qu'il y a dans chaine.
                                                Donc copie vaut ce qu'il y a dans le tableaux de chaine, c'est
                                                à dire: texte. Si on avait fait l'inverse: chaine, copie, on
                                                aurait eut 0, car on aurait dit chaine vaut ce qu'il y a dans
                                                copie, donc 0, puisque copie vaut zero.
                                                Plus loin un autre exemple avec a et b.
                                                La variable a prend ce qu'il y a dans b.
                                                L'on dit: a prend la valeur de b, donc 0 devient 4.*/

    printf("%s\n", chaine);
    printf("%s\n", copie);

int a = 0, b = 4;

printf("%d",copiecolle (a,b));
    return 0;
}

int copiecolle(int a, int b)
{
 a = b;
 return a;

}
