#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int n = 4, l = 0, c = 0; /*c1 = 0*/

    for(l = 0; l <= n; l++)
    {
        for(c = 0; c <= l; c++) /*La boucle la plus intérieur s'exécute en premier, une fois effectue le compilateur sort de
                                la boucle et suit les instructions suivantes, puis remonte dans la boucle la plus extérieure
                                tant que celle-ci n'est pas fini, elle retourne dans la boucle intérieur, qui elle repart à zéro.
                                Cela donne la figure du triangle. */
        {
            printf("*");
        }
        printf("\n");
    }
        printf("\n");
     for(l = 0; l <= n; l++)
    {
        for(c = 0; c <= n; c++) /*même chose, sauf que la boucle intérieur, sur la ligne, s'exécute tant quelle est inférieure à
                                n, ce qui donc va donner n fois le motif sur la ligne, cela va donner un aspect carre.*/
        {
            printf("*");
        }
        printf("\n");
    }

        printf("\n");
   /* for(c1 = n; c1 <= n; c1--)
    {
        printf("*");
    }*/
    return 0;
}
