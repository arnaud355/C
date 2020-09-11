#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"

char lireCaractere()
{
char caractere = 0;
caractere = getchar();    /*L'utilisateur entre une lettre, cette fonction getchar() est une fonction de stdio
                            elle revient au même que d'écrire: scanf("%c", &lettreEntre), sauf que la diff
                            est que l'on pourras ne pas prendre en compte la touche Entree, voir ci-dessous. */

caractere = toupper(caractere);/*La fonction toupper va mettre en majuscule le caractère, si ce n'est déjà fait.*/

while(getchar() != '\n');   /*Contrairement à la fonction scanf qui enregistre la touche Entree, ce qui fausse
                            le programme si l'on veut faire appelle à la fonction scanf dans le même code source
                            l'on peut avec cette fonction getchar faire une boucle jusqu'à ce que l'utilisateur
                            appuie sur Entree. Si par mégarde ou pour faire chier le monde l'utilsateur a
                            entrée un mot et non une lettre, c'est la première lettre qui seras pris en compte
                            Les autres lettres seront vidés de la mémoire, on dit qu'on vide le buffer.*/

}

void recherche(const char* motSecret, char* lettreEntre, int longueurChaine)
{

    int i = 0;
    for(i = 0; i < longueurChaine; i++)
    {
        if(motSecret[i] == lettreEntre)
        {
           motSecret[i] = lettreEntre;
        }

    }

}
