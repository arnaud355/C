#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(int argc, char *argv[])
{
    Coordonnees monpoint;           /*On à une variable monpoint de type Coordonnees c à dire que la variable
                                    monpoint prend en paramètre les variables contenu dans le type Coordonne*/

    initialiserCoordonnees(&monpoint);  /*On envoie à la fonction l'adresse de monpoint pour modifier des valeurs
                                        de struct Coordonnees (qu'on appelle nomdela composante),
                                        etant donne que c une adresse on peut modifier
                                        en retour plusieurs variables*/
    printf("%d", monpoint.x);
    printf("%d", monpoint.y);
    return 0;
}

void initialiserCoordonnees(Coordonnees *monpoint)
{
(*monpoint).x = 0;                                 /*raccourci: au lieu d'utiliser le (*point).x
                                                on peut mettre aussi pour un pointeur: point->x = 0;*/
(*monpoint).y = 0;


}
