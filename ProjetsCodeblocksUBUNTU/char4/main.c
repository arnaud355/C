#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int eiaco(const char* mot);

int main(int argc, char *argv[])
{
    char mot[] = "Hello";    //L'on va creer une fonction similaire à strlen (qui calcule longeur chaine).

    int longeurMot = 0;

    longeurMot = eiaco(mot); //eiaco est une fonction qui fait la même chose que strlen.

    printf("le mot %s fait %d lettres",mot, longeurMot);

    return 0;
}

int eiaco(const char* mot)  /*char* mot revient exactement au même que char mot[]. ça n'a pas de rapport
                                avec les pointeurs, dans ce cas on s'en fout de ce que contient mot, on
                                veut juste le nombre de cases.*/
{

int nombreDeLettre = 0;
char finDeChaine = 0;

do {

    finDeChaine = mot[nombreDeLettre];  /*La variable nombredelettre, (valable dans la fonction) va parcourir
                                         les cases de mot, étant donné que c une chaine de caractère, cela
                                         s'arrête à /0.*/
    nombreDeLettre++;

    } while (finDeChaine != '\0');

    nombreDeLettre--;           //On retire une lettre, car le mot compte un tour de plus avec le \0.
    return nombreDeLettre;
}
