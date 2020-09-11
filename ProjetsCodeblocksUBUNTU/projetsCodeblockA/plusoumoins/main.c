#include <stdio.h>
#include <stdlib.h>
#include <time.h>   // on inclut la bibliotheque qui permet de generer un nombre aleatoire

int main(int argc, char *argv[])
{
    int nombreMystere = 0, nombreEntre = 0;
    const int Max = 100, Min = 1;            // constance de chaque essais, le nombre mystere est compris entre 1 et 100

    int continuezpartie = 1;

    srand(time(NULL));   // srand est la fonction qui va prendre en parametre la bibliotheque time et inscrire NULL
    nombreMystere = (rand() % (Max - Min + 1)) + Min; // nombre mystere prend en compte un nombre aleatoire rand, compris entre max et min

    while(continuezpartie != 0)
    {

    do
    {
        printf("Quel est le nombre?\n");
        scanf("%d", &nombreEntre);   // on compare le nombre entre avec le nombre mystere choisi par l ordi

        if (nombreMystere > nombreEntre)
        printf("c est plus\n\n");

        else if (nombreMystere < nombreEntre)
        printf("c est moins\n\n");

        else (nombreEntre = nombreMystere)
        {
        printf("\nBravo vous avez gagne en trouvant le nombre mystere en %d coups\n\n", coups);
        printf("Voulez vous faire une autre partie? Appuyez sur 0 pour arreter\n");
        scanf("%d", &continuezpartie);
        }

        coups++;

    }while(continuezpartie != 0);

    }


}



