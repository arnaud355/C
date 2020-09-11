#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"
#define bool char
#define TRUE 1
#define FALSE 0

int sommeTableau(int tab[], int taille){ // int tab[] égal int *tab
    int somme = 0, i = 0;

    for(i = 0; i < taille; i++){
        somme = somme + tab[i];
    }
    return somme;
}
double moyenneTableau(int tab[],int taille){
     int somme = 0, i = 0;
     double moyenne = 0;

     for(i = 0; i < taille; i++){
        somme = somme + tab[i];
    }
    moyenne = somme / taille;
    return moyenne;
}
void copie(int tableauOriginal[], int tableauCopie[], int tailleTableau){
    int i = 0;
      for(i = 0; i < tailleTableau; i++){
        tableauCopie[i] = tableauOriginal[i];
    }
}
void maximumTableau(int tab[], int tailleTableau, int valeurMax){
    int i = 0;
      for(i = 0; i < tailleTableau; i++){
        if(tab[i] > valeurMax){
            tab[i] = 0;
        }
    }
}
void ordonnerTableau(int tabDesordre[],int tailleTableau){
    char permut = 1;
    int tmp = 0, i = 0;
        while(permut){
            permut = 0;
            for(i = 0; i < tailleTableau; i++){
                if(tabDesordre[i] > tabDesordre[i + 1]){
                    tmp = tabDesordre[i];
                    tabDesordre[i] = tabDesordre[i + 1];
                    tabDesordre[i + 1] = tmp;
                    permut = 1;
                }
            }
        }
}
