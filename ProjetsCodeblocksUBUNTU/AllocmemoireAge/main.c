#include <stdio.h>
#include <stdlib.h>

void* malloc(size_t nombreOctetsNecessaires);
void free(void* pointeur);

int main(int argc, char *argv[])
{
    int* memoireAllouee = NULL;            //Au début c'est un pointeur sans adresse, sans valeurs.

    memoireAllouee = malloc(sizeof(int));  /*Ensuite pointeur prend malloc qui lui envoie la taille
                                            du type par l'intermédiare de la fonctionnalité sizeof.
                                            pointeur memoireAllouee reserve dnas le cas du type int
                                            4 octets en memoire, soit 4 cases adresses*/
    if(memoireAllouee == NULL)
    {
        exit(0);

    }
    printf("Quel age avez-vous?");
    scanf("%d", memoireAllouee);
    printf("Vous avez %d ans\n", *memoireAllouee);  //Donne moi la valeur qui se trouve à cette adresse.

    free(memoireAllouee);
    return 0;
}
