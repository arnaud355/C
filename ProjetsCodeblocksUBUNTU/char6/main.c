#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* strch(const char* chaine, int caractereARechercher);


                                                            /*On à alloué cette fonction dans un pointeur, qui
                                                            est suiteChaine, c'est une adresse, et l'on demande
                                                            les valeurs qui se trouvent à ces adresses, en l'
                                                            occurence, on pointe sur tableau chaine, on recherche
                                                            le caractere d, et l'on place les mots après d, dans
                                                            le tableau char* strch, qui est renvoyé dans
                                                            suiteChaine*/

int main(int argc, char *argv[])
{
    char chaine[] = "Texte de test", *suiteChaine = NULL;

    suiteChaine = strchr(chaine, 'd');                      /*Suite chaine est une variable qui contient une
                                                            adresse, qui contient la fonction, celle-ci nous
                                                            amene à pointer sur les variables (caractere dans
                                                             ce cas) à l'intérieur de chaine, suiteChaine
                                                             s'arrête à d dans ce cas, (on recherche la valeur
                                                             qui se trouve à cette adresse, voir prototypr)*/

    if(suiteChaine != NULL)
    {
        printf("Voici la fin de la chaine a partir du premier d: %s", suiteChaine);

    }
    return 0;
}
