#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int n = 4, l = 0, c = 0; /*c1 = 0*/

    for(l = 0; l <= n; l++)
    {
        for(c = 0; c <= l; c++) /*La boucle la plus int�rieur s'ex�cute en premier, une fois effectue le compilateur sort de
                                la boucle et suit les instructions suivantes, puis remonte dans la boucle la plus ext�rieure
                                tant que celle-ci n'est pas fini, elle retourne dans la boucle int�rieur, qui elle repart � z�ro.
                                Cela donne la figure du triangle. */
        {
            printf("*");
        }
        printf("\n");
    }
        printf("\n");
     for(l = 0; l <= n; l++)
    {
        for(c = 0; c <= n; c++) /*m�me chose, sauf que la boucle int�rieur, sur la ligne, s'ex�cute tant quelle est inf�rieure �
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
