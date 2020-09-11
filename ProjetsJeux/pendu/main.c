#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "fonctions.h"

int main(int argc, char *argv[])
{
    int mode = 0;
    char verif = 0;
do {
    printf("Choissisez votre mode:\n");
    printf("mode un joueur tapez 1, mode deux joueurs tapez 2:\n");
    scanf("%d", &mode);
    if(mode == 1){
        verif = 'o';
    }
    else if(mode == 2){
        verif = 'o';
    }
}while(verif != 'o');

if(mode == 1){

    char jouer = 0;
do{
    int i = 0, longueurMotADeviner = 0, coupure = 0, posTaille = 0;
    int emplacement = 0, result = 0, coups = 10;
    char lettre = 0;

    char *motEtoile = NULL;
    char motADeviner[26];
    int *tabGagne = NULL;
        recupererMot(motADeviner);
        printf("%s\n", motADeviner);


        longueurMotADeviner = strlen(motADeviner);
   do{
            if(longueurMotADeviner < 2){
        recupererMot(motADeviner);
        }
    }while(longueurMotADeviner < 2);

    //printf("longueur mot:%d\n",longueurMotADeviner);

    redimensionneTaille(&motEtoile,longueurMotADeviner);
/*On a envoyé à la fonction redimensionneTaille, l'adresse de l'adresse de motEtoile
(rappel un tableau comme motEtoile, ou qu elle que soit le type, un tableau renvoi
 à l'adresse de son premier indice, donc si on avait envoyé juste l'adresse, c'est
 à dire motEtoile, ensuite dans la fonction si on modifie l'adresse de l'adresse
 c'est à dire *motEtoile pour lui redonner une nouvelle taille, cela n'aurait été
 valide que dans la fonction, ça aurait été effacé à l fin de la fonction elle-même
 donc il faut envoyer l'adresse de l'adresse, donc reception d'un:  type ** dans
 les arguments de la fonction, pour qu'elle puisse renvoyer à l'adresse d'adresse*/

    coupure = longueurMotADeviner - 1;

    for(i = 0; i < longueurMotADeviner; i++){
        motEtoile[i] = '*';
        if(i == coupure){
                motEtoile[i] = '\0';
                posTaille = i; //Dans posTaille se trouve maintenant la coupure \0
            }
    }

    redimensionneTNumerique(&tabGagne,posTaille);

     for(i = 0; i < posTaille; i++) {
        tabGagne[i] = 0;
    }




printf("=============Bienvenue dans le Jeu du Pendu=============\n");

do{
        printf("Il vous reste %d coups a jouer\n", coups);
        printf("Quel est le mot secret? %s\n", motEtoile);
        printf("Proposer une lettre:");
        lettre = lireCaractere();

        for(i = 0; i < posTaille; i++){
            if(lettre == motADeviner[i]){
                emplacement = i;
                motEtoile[emplacement] = lettre;
                tabGagne[emplacement] = 1;

                result = result + tabGagne[emplacement];
                    if(result == posTaille){
                        printf("Bravo vous avez gagne!\n");
                        coups = 0;

                    }
            }

        }

        if(lettre != motADeviner[emplacement]){
                coups = coups - 1;
                    switch(coups){
                        case 9: printf("|\n");
                        break;
                         case 8: printf("|\n");
                                    printf("|\n");
                        break;
                         case 7: printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                        break;
                         case 6: printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                        break;
                         case 5: printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                        break;
                         case 4: printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                        break;
                         case 3: printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                        break;
                         case 2: printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("o\n");
                        break;
                         case 1: printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("o\n");
                                    printf("()\n");
                        break;
                         case 0: printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("o\n");
                                    printf("()\n");
                                    printf("||\n");
                                    printf("Perdu\n");

                                    break;
                    }

            }

    }while(coups != 0);

    printf("Voulez-vous rejouer? o ou n");
    jouer = lireCaractere();

                free(motEtoile);
                free(tabGagne);

}while(jouer != 'n');

    } //-------------------------------------------------------------------------
    else if(mode == 2){
            char jouer = 0;
        do {
            char mot[26];
            char vrai = 'o';
            char *tabEtoile = NULL;
            int *tabGagne = NULL;
            int longueur = 0, i = 0,result = 0, emplacement = 0;
            int coups = 10;
            char lettre = 0, lettreVerif = 0;

                printf("Vous etes en mode deux joueurs\n");
            while(vrai == 'o'){
                vrai = 'n';
                printf("Joueur 1 entrez un mot a faire deviner:");
                fgets(mot,26,stdin);
                lire(mot,26);
                longueur = strlen(mot);

                for(i = 0; i < longueur; i++){

                    lettreVerif = mot[i];
                    lettreVerif = tolower(lettreVerif);
                        if (lettreVerif < 97 || lettreVerif > 122){
                              vrai = 'o';
                            printf("\nVotre mot n'est pas valide il contient des chiffres");
                        }
                    }

                }

                longueur = strlen(mot);/*La longueur est pile celle du mot car un
            mot entrez par l'utilisateur voit sa taille calculee pile et ne
            prend pas en compte le \0*/
            redimensionneTaille(&tabEtoile,longueur);

            for(i = 0; i < longueur; i++){
                tabEtoile[i] = '*';

                }


           redimensionneTNumerique(&tabGagne,longueur);

             for(i = 0; i < longueur; i++){
                tabGagne[i] = 0;
            }




            do{
            printf("Il vous reste %d coups a jouer\n", coups);
            printf("Quel est le mot secret? %s\n", tabEtoile);
            printf("Joueur 2 entrez une lettre:");
            lettre = lireCaractere();


             for(i = 0; i < longueur; i++){
                if(lettre == mot[i]){
                    emplacement = i;
                    tabEtoile[emplacement] = lettre;
                    tabGagne[emplacement] = 1;

                    result = result + tabGagne[emplacement];
                        if(result == longueur){
                            printf("Bravo vous avez gagne!");
                            printf("%s\n",tabEtoile);
                            coups = 0;

                    }
                }

            }

                if(lettre != mot[emplacement]){
                    coups = coups - 1;
                    switch(coups){
                        case 9: printf("|\n");
                        break;
                         case 8: printf("|\n");
                                    printf("|\n");
                        break;
                         case 7: printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                        break;
                         case 6: printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                        break;
                         case 5: printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                        break;
                         case 4: printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                        break;
                         case 3: printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                        break;
                         case 2: printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("o\n");
                        break;
                         case 1: printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("o\n");
                                    printf("()\n");
                        break;
                         case 0: printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("|\n");
                                    printf("o\n");
                                    printf("()\n");
                                    printf("||\n");
                                    printf("Perdu\n");

                                    break;
                    }


                }
            }while(coups != 0);

                printf("Voulez-vous rejouer? o ou n");
                jouer = lireCaractere();

                free(tabEtoile);
                free(tabGagne);

        }while(jouer != 'n');

    }
    return 0;
}


