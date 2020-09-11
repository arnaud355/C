#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>      /*C'est une librairie pour la fonction toupper()*/
#include <string.h>

int main(int argc, char* argv[])
{
    char lettre = 0; /* Stocke la lettre proposée par l'utilisateur (retour du scanf)*/
    char motSecret[] = "MARRON";    /*C'est le tableau à trouver*/
    int lettreTrouvee[6] = {0}; /*Tableau de booléens. Chaque case correspond à une lettre du mot secret.
                                    0 = lettre non trouvée, 1 = lettre trouvée*/
    int coupRestants = 10; /*Compteur de coups restants (0 = mort)*/
    int i = 0; /*Une petite variable pour parcourir les tableaux*/
    printf("Bienvenue dans le Pendu!\n\n");

    while (coupRestants > 0 && !gagne(lettreTrouvee))
    {
    printf("\n\nIl vous reste %d coups a jouer", coupRestants);
    printf("\nQuel est le mot secret?");
    /*On affiche le mot secret en masquant les lettres non trouvées
    Exemple: *A**ON */
    for(i = 0; i < 6; i++)
    {
        if(lettreTrouvee[i])
        {    /*Si on a trouvé la lettre numéro i*/
        printf("%c", motSecret[i]);  /*On l'affiche*/
        }
        else
        {
        printf("*"); /* Sinon on affiche une étoile pour les lettres non trouvées*/
        }

    }
        printf("\nProposer une lettre :");
        lettre = lireCaractere();

        /*Si ce n'est pas la bonne lettre*/
        if(!rechercheLettre(lettre, motSecret, lettreTrouvee))
            {
                coupsRestant--; /*On enlève un coup au joueur*/
            }

        if(gagne(lettreTrouvee))
        {
            printf("\n\nGagne ! Le mot secret était bien: %s", motSecret);
        }
        else
        {
            pintf("\n\nPerdu ! Le mot secret était: %s", motSecret);
        }

    }
    return 0;
}
