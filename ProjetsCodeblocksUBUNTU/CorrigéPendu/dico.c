#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "dico.h"

int piocherMot(char *motPioche)
{
    FILE* dico = NULL; /*Le ponteur de fichier qui va contenir notre fichier*/
    int nombreMots = 0, numMotChoisi = 0, i = 0;
    int caractereLu = 0;

    dico = fopen("dico.txt", "r"); /*On ouvre en lecture seule*/
    /*On vérifie si on a reussi à ouvrir le dictionnaire*/
    if(dico == NULL) /*Si on n'a pas reussi à ouvrir le dictionnaire*/
    {
        printf("\nImpossible de charger le dictionnaire de mots");
        return 0; /*On retourne 0 pour indiquer que la fonction a échoué*/
        /*A la lecture du return, la fonction s'arrête immédiatement*/
    }
    /*On compte le nombre de mots dans le fichier (il suffit de compter les entrées \n*/
    do
    {
        caractereLu = fgetc(dico);
        if(caractereLu == '\n')
        nombreMots++;
    } while(caractereLu != EOF);

    numMotChoisi = nombreAleatoire(nombreMots); /*On pioche un mot au hasard*/
    /*On recommence à lire le fichier depuis le début. On arrête lorsqu'on est arrivé au bon mot*/
    rewind(dico);
    while(numMotChoisi > 0)
    {
        caractereLu = fgetc(dico);
        if(caractereLu == '\n')
        numMotChoisi--;
    }
}





