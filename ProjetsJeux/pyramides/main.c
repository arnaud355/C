#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int nb = 0, i = 0, j = 0, nl = 0;

   while(nb < 1 || nb > 10){
        printf("Entrez votre nombre (Entre 1 et 10):");
        scanf("%d\n",&nb);
   }
   printf("Votre nombre avec la pyramide en carre:\n");
   for(i = 0; i < nb; i++){
        for(j = 0; j < nb; j++){
            printf("*");
        }
        printf("\n");
   }

   printf("Votre nombre avec la pyramide en classique:\n");
   for(i = 0; i < nb; i++){
        for(j = 0; j <= i; j++){
            printf("*");
        }
        printf("\n");
   }

        nl = nb;
   printf("Votre nombre avec la pyramide en inverse:\n");
   for(i = 0; i < nb; i++){
        for(j = nl; j > 0; j--){
            printf("*");
        }
        printf("\n");
        nl = nl - 1;
   }

    return 0;
}
