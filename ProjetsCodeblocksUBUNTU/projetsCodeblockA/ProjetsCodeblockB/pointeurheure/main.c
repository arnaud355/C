#include <stdio.h>
#include <stdlib.h>

 void decoupeMinutes(int *pointeursurheure, int *pointeursurminutes);

int main(int argc, char *argv[])
{
    int heure = 0, minutes = 90;


    decoupeMinutes(&heure,&minutes);
    printf("%d heure et %d minutes", heure, minutes);


    return 0;
}
 void decoupeMinutes(int *pointeursurheure, int *pointeursurminutes)
 {

    *pointeursurheure = *pointeursurHeure / 60;
    *pointeursurminutes = *pointeursurMinutes % 60;
 }
