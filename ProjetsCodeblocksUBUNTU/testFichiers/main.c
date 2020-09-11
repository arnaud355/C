#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"


int main(int argc, char *argv[])
{
    FILE* fichier = NULL;               //l'étoile de la première ligne sert à déclarer un pointeur

    fichier = fopen("test.txt","r+");   /*on à mis la fonction dans un pointeur fichier, c'est un pointeur
                                        qui contient la fonction fopen. On aurait pu mettre directement
                                        la fonction fopen, mais par la suite fichier nous donne un point
                                        de repère. De plus pour la fermeture c moins lisible d'envoyer
                                        une fonction avec un type FILE* dans fclose*/

    if(fichier != NULL)
    {

    fputc('A', fichier);
    fputs("Salut les zeros\nComment allez vous?", fichier);
    fclose(fichier);
    }
    else
    {
        printf("Imposssible d ouvrir!");
    }
    return 0;
}
