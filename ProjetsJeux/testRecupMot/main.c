#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "fonctions.h"
#include <ctype.h>

int main(int argc, char *argv[])
{
    /*int nbAleatoire = 0, caracteres = 0, nbCaractere = 0, min = 1, compteur = 0;
    int i, lettres = 0;
    //char* mot = NULL;
    char mot[25];
    FILE* Rom = NULL;
    Rom = fopen("Rom.txt", "r");
    do {
        caracteres = fgetc(Rom);
        nbCaractere = nbCaractere + 1;
    } while(caracteres != EOF);
    rewind(Rom);
        srand(time(NULL));
        nbAleatoire = (rand()%(nbCaractere - min + 1)) + min;


    if(Rom != NULL){

        do {
                i = 0;
                lettres = fgetc(Rom);
                if(lettres != ' ' || lettres != '\n'){

                    mot[i] = lettres;
                    i = i + 1;
                }
                else{
                    mot[i] = '\0';
                    compteur = compteur + 1;
                }

        }while(compteur <= nbAleatoire);
        printf("%s", mot);
       fclose(Rom);

    }
    else {
        printf("Impossible d'ouvrir le fichier Dico");
    }*/
  /*  char mot[25];
int longueur = 0, j = 0, taille = 0;*/


/*
    do {
        mot2 = mot[i];
        i = i + 1;
    }while(mot2 != '\0');
   taille = i;

*/
 /*
    taille = taille - 1;
 for(j = 0; j < taille; j++){
        printf("%d",tab[j]);
    }
*/
/*char mot2 = 0;
    printf("votre mot:\n");
    scanf("%s",mot);
    printf("%s\n", mot);
    longueur = strlen(mot);
    printf("longueur du mot:%d\n",longueur);*/
/*
int* tab = NULL;
int j = 0, taille = 4;

dimensionTaille(&tab, taille);Si on avait mis tab on aurait envoyer une adresse
et dans la fonction dimensionTaille si on avait mis un int *tab on aurait recupéré
l'adresse, c'est un passage par valeur, si on avait travaillé dans la fonction
sur des valeurs et non *tab cela aurait marché, mais comme on travaille également
sur une adresse, recupéré dans une adresse envoyé par une adresse, l'adresse,
les modif apportées ne marcheront que localement. il faut envoyer une adresse de
l'adresse, recupérer une adresse de l'adresse, d où les deux **, et l'envoi de
l'adresse d'adresse &tab , pour travailler sur l'adresse et la renvoyer direcetment
par ricochet dans la procédure principale
*/
  /*  for(j = 0; j < taille; j++){
        tab[j] = 0;
    }
    for(j = 0; j < taille; j++){
        printf("%d",tab[j]);
    }


    free(tab);*/
    char mot[10];
    int longueur = 0, j = 0,coupure = 0;
    char *etoiles;
    char lettre = 0;
     FILE* Rom = NULL;
    Rom = fopen("Rom.txt", "r");

     if(Rom != NULL){

        fgets(mot,10,Rom);

     }
     else{
         printf("Impossible d'ouvrir le fichier Dico");
     }
     printf("%s\n", mot);
     longueur = strlen(mot);
     dimensionTaille(&etoiles, longueur);
     printf("longueur:%d\n",longueur);
      fclose(Rom);

        coupure = longueur - 1;
        for(j = 0; j < longueur; j++){
            etoiles[j] = '*';
            if(j == coupure){
                etoiles[j] = '\0';
            }
    }

        printf("%s",etoiles);
        printf("entrez caractere:");
        lettre = lireCaractere();
        printf("la lettre est: %c", lettre);
        char mot2[10];
printf("entrez mot:");
scanf("%s", mot2);
longueur = strlen(mot2);
printf("longueur:%d", longueur);
      free(etoiles);

    return 0;
}
