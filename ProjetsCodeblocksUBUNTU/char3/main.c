#include <stdio.h>
#include <stdlib.h>
#include <string.h>  /* J'inclus la bibliotheque string, car je vais faire appels à des fonctions sur des
                        string (chaines), l'ordi doit connaitre le prototype des fonctions de cette bibli.*/

int main(int argc, char *argv[])
{
    char chaine[] = "Salut";
    int longeurChaine = 0;

    longeurChaine = strlen(chaine); //On récupère la longeur de la chaine dans longeurChaine.
                                    /*strlen est une fonction deja existante qui calcule la taille d'une
                                    chaine de caracteres.*/
    printf("La chaine %s fait %d caracteres de long", chaine, longeurChaine);

                                    /*strlen(chaine) est envoye à une fonction de string:
                                    size_t strlen(const char* chaine); size_t est un type inventé,
                                    il signifie que strlen renvoie un nombre. Entre parenthese il reçoit
                                    chaine, avec char* cela permet d'avoir sa taille directement (Attention
                                    ce n'est valable que pour les tableaux de chaines de caractères.
                                    Pour les autres tableaux avec des valeurs, il faut préciser quelquepart
                                    la taille. Le const siginifie que la taille ne doit pas être modifié*/
    return 0;
}
