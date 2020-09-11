#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "fonctions.h"
#define taille_Max 26

 void recupererMot( char* motADeviner){//tout comme tab de type int c'est déjà un pointeur
//La fonction ne fais que copier, motadeviner est dejà un pointeur car tableau.
 int lettres = 0, ligneAleatoire = 0, retourLigne = 0, nbMots = 0, min = 1;
 int i = 0, compteurLigne = 0;

    FILE* Dico = NULL;
    Dico = fopen("Dico.txt", "r");
    do{
        compteurLigne = fgetc(Dico);
        if(compteurLigne == '\n'){
            nbMots = nbMots + 1;
        }
    } while(compteurLigne != EOF);
        rewind(Dico);

        srand(time(NULL));
        ligneAleatoire = (rand()%(nbMots - min + 1)) + min;




    if(Dico != NULL){
        do {

                lettres = fgetc(Dico);
            if(lettres == '\n'){
                retourLigne = retourLigne + 1;
                    if(retourLigne == ligneAleatoire){
                            fgets(motADeviner,taille_Max,Dico);
                             i = i + 1;
                        }
                    }

        }while(lettres != EOF);

        fclose(Dico);
    }
    else {
        printf("Impossible d'ouvrir le fichier Dico");
    }
 }

void redimensionneTaille(char** mot, int taille){

    *mot = malloc(taille * sizeof(char));
    if(mot == NULL){
        exit(0);
    }
}

void redimensionneTNumerique(int** tab, int taille){

     *tab = malloc(taille * sizeof(int));
    if(tab == NULL){
        exit(0);
    }
}

char lireCaractere(){
    char caractere = 0;
    caractere = getchar(); //Lit uniquement le premier caractere

    caractere = tolower(caractere);

    while(getchar() != '\n'); /*le ; dit on fait rien dans la boucle, comme un { }
    //On vide le getchar de toutes les lettres jusqu'à la touche entrée, le premmier
    est déjà stocké dans la variable caractere */
    return caractere; //On retourne le premier caractere qu'on a lu
}

void viderBuffer(){
    int c = 0;
    while(c != '\n' && c!= EOF){
        c = getchar();
    }
}

int lire(char *chaine, int longueur){
    char *positionEntree = NULL;

    //On lit le texte saisi au clavier
    if(fgets(chaine,longueur, stdin) != NULL){//Pas d'erreurs de saisi
        positionEntree = strchr(chaine,'\n');//On recherche l'entrée
        if(positionEntree != NULL){//Si on a trouvé le retour à la ligne
            *positionEntree = '\0';/*Permet d'avoir: zebre\0 et non zebre\n car
            sinon le \n soit l'entree (ou un espace), est stocké dans le buffer
            et à la prochaine saisie de l'utilisateur c'est ce qui est dans le
            buffer, en stock, qui est entré*/
        }
        else{
            viderBuffer();
        }
        return 1;//On renvoie 1 si fonction sans erreur
    }
    else{
        viderBuffer();
        return 0; //On renvoie 0 s'il y a une erreur
    }
}
