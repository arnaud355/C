#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char lettre = 'a';

    printf("%c\n",lettre); /* %c nous donne la valeur de lettre (qui est un chiffre mais grâce à la table ascii
                                il y a une conversion de lalphabet*/

    printf("%d\n", lettre); // Cela nous donne le numero de la lettre. (c un numéro pour l'ordi).

    char lettre2 = 'B';

    scanf("%c\n", &lettre2);

    printf("%c\n", lettre2);

    char chaine[] = "Salut"; /* J'ai déclaré une variable chaine (qui est un tableau de lettres, bien entendu
                                pour l'ordi se sont des chiffres) pour y introduire le mot Salut.
                                J'aurais pu écrire aussi: char* chaine =...(comme une déclaration de pointeurs).
                                les lettres d'un mot sont stockés dans un tableaux, la taille du mot (son nombre
                                de lettres) est calculé automatiquement, on peut donc le faire afficher à l'aide
                                d'un printf. Mais le probleme est que le calcul automatique ne se fait qu'a
                                l'initialisation. Plus loin dans le code source il faudra entrer la taille
                                manuellement. Voir le projet char2 */

    printf("%s", chaine); // On affcihe le mot avec un %s, c'est le s de string (qui veut dire chaine).

    return 0;

}
