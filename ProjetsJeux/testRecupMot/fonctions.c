#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "fonctions.h"
#include <ctype.h>

void dimensionTaille(char** tableau, int taille){
   *tableau = malloc(taille * sizeof(char));
    if(tableau == NULL){
        exit(0);
    }
}
void dimensionTNumerique(int **tableauNum, int taille){
   *tableauNum = malloc(taille * sizeof(char));
    if(tableauNum == NULL){
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
