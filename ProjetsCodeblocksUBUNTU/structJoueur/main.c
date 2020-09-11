#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main(int argc, char *argv[])
{
    Personne joueur[3];             /*Personne est l'allias de struc Personne, c'est un type qui contient
                                    plusieurs variables, on donne dans ce cas le type Personne à la variable
                                    joueur. (On à mit Personne en commançant par une maj car cela là différencie
                                    d'une simple variabel). La variable joueru est un tableau dans ce cas.
                                    Pour faire appelle à une variable composant la struct Personne il faut mettre
                                    variable.variableContenuDansStructPeronne.*/
    int i = 0;
    int oui = 1;



    for(i = 0;i < 1;i++)
    {
    printf("Quel est votre prenom joueur1?\n");
    scanf("%s",joueur[0].prenom);
    printf("Quel est votre nom?\n");
    scanf("%s",joueur[0].nom);
    printf("Quel est votre pseudo?\n");
    scanf("%s",joueur[0].pseudo);
     printf("Quel est votre prenom joueur2?\n");
    scanf("%s",joueur[1].prenom);
    printf("Quel est votre nom?\n");
    scanf("%s",joueur[1].nom);
    printf("Quel est votre pseudo?\n");
    scanf("%s",joueur[1].pseudo);
     printf("Quel est votre prenom joueur3?\n");
    scanf("%s",joueur[2].prenom);
    printf("Quel est votre nom?\n");
    scanf("%s",joueur[3].nom);
    printf("Quel est votre pseudo?\n");
    scanf("%s",joueur[3].pseudo);
    }

    printf("joueur1 vous etes %s %s et votre pseudo est %s\n",joueur[0].prenom,joueur[0].nom,joueur[0].pseudo);
    printf("joueur2 vous etes %s %s et votre pseudo est %s\n",joueur[1].prenom,joueur[1].nom,joueur[1].pseudo);
    printf("joueur3 vous etes %s %s et votre pseudo est %s\n",joueur[1].prenom,joueur[1].nom,joueur[1].pseudo);
    printf("Voulez-vous des infos sur joueur1? entrez 1 pour oui ou 0 pour non!\n");

    scanf("%d",&oui );

    if(oui == 1)
    {
       printf("joueur1 s appelle %s %s et son et pseudo est %s\n",joueur[0].prenom,joueur[0].nom,joueur[0].pseudo);
    }
    else
    {
        printf("En revoir!");
    }


    return 0;
}
