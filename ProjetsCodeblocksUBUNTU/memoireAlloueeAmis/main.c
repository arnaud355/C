#include <stdio.h>
#include <stdlib.h>

void* malloc(size_t nombreOctetsNecessaires);
void free(void* pointeur);

int main(int argc, char *argv[])
{
  int nombreDAmis = 0, i = 0;
  int* ageAmis = NULL;      /*Ce pointeur va servir de tableau après l'appel du malloc.*/

  printf("Combien d'amis avez-vous?");/*On demande le nombre d'amis à l'utilisateur.*/
  scanf("%d", &nombreDAmis);

  if(nombreDAmis > 0)  /*Il faut qu'il ait au moins un amis(je le plains un peu sinon).*/
  {
    ageAmis = malloc(nombreDAmis * sizeof(int));/*On alloue de la mémoire pour le tableau, avec la fonction
                                                malloc. sizeof(type variable) est une fonctionnalité de base
                                                qui calcule la taille d'un type de variable ou structure.
                                                L'allocation dynamique permet notamment de créer un tableau
                                                dont la taille est déterminée par une variable au moment
                                                de l'exécution.*/

    if(ageAmis == NULL)
    {
        exit(0);    /*Signifie: On arrête tout.*/
    }

    for(i = 0; i < nombreDAmis; i++)    /*On demande l'âge des amis un à un.*/
    {
        printf("Quel age a l'ami numero %d?", i + 1); /*Pourquoi i + 1: car i = 0, il faut dire amis numéro
                                                        1 pour que ça reste compréhensible pour l'utilsateur
                                                        même si en réalité ami 1 est stocké à l'adresse zero.*/
        scanf("%d", &ageAmis[i]);
    }

    printf("\n\nVos amis ont les ages suivants:\n");/*On affiche les âges stockés un à un.*/
    for(i = 0; i < nombreDAmis; i++)
    {
        printf("%d ans\n", ageAmis[i]);

    }

    free(ageAmis);  /*On libère la mémoire allouée avec malloc, on n'en a plus besoin.*/
    }
    return 0;
}
