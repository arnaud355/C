#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include "constantes.h"
#include "fichier.h"

int chargerNiveau(int niveau[][NB_BLOCS_HAUTEUR]){
    FILE* fichier = NULL;
    char ligneFichier[NB_BLOCS_LARGEUR * NB_BLOCS_HAUTEUR + 1] = {0};
    //le + 1 dans le tableau ligneFichier correspond au \0, puisque que c'est un tableau de chaîne
    int i = 0,j = 0;

    fichier = fopen("niveaux.txt","r");
    if(fichier == NULL)
        return 0;

    /*Le fichier niveau.txt contient une ligne qui est une suite de nombres , chaque nombre repésente une case du niveau:
    111110001111111140000111111100000000111111121110000300001112000*/

    //On va lire cette ligne avec un fgets:
    fgets(ligneFichier,NB_BLOCS_LARGEUR * NB_BLOCS_HAUTEUR + 1,fichier);

/*On va analyser le contenu de ligneFichier. On sait que les 12 premiers caractères représentent la première ligne
et les 12 suivants la seconde ligne,etc*/

    for(i = 0; i < NB_BLOCS_LARGEUR; i++){
        for(j = 0; j < NB_BLOCS_HAUTEUR; j++){
            switch(ligneFichier[(i * NB_BLOCS_LARGEUR) + j]){
            case '0':
                niveau[j][i] = 0;
                break;
            case '1':
                niveau[j][i] = 1;
                break;
            case '2':
                niveau[j][i] = 2;
                break;
            case '3':
                niveau[j][i] = 3;
                break;
            case '4':
                niveau[j][i] = 4;
                break;
            }
        }
    }
    /*Par un simple calcul on prend le paramètre qui nous intéresse dans ligneFichier.
    Ce sont des lettres qui sont stockées dans le fichier(ligneFichier est de type char, donc tab stocke des caractères,
    les nombres y sont convertis en chaine de caractères,
    et pour accéder à un élement (une des lettres) d'un tab de ce type il faut le mettre entre apostrophes).
    Je veux dire par là que '0'est stocké comme le caractère ASCII '0',et non avec case 0.
    le 48 correspond au caractère ASCII de 0.  */
    fclose(fichier);
    return 1;//On envoie 1 pour dire que tout c'est bien passé)
}

int sauvegarderNiveau(int niveau[][NB_BLOCS_HAUTEUR]){
    FILE* fichier = NULL;
    int i = 0,j = 0;

    fichier = fopen("niveaux.txt","w");
    if(fichier == NULL)
        return 0;

    for(i = 0; i < NB_BLOCS_LARGEUR; i++){
        for(j = 0; j < NB_BLOCS_HAUTEUR; j++){
            fprintf(fichier,"%d",niveau[j][i]);
        }
    }
    //fprintf traduis les nombres du tableaux niveau en caractères ASCII, afin de les stocker dans le fichier de type file
    fclose(fichier);
    return 1;
}
