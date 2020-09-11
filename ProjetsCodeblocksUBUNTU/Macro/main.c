#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAJEUR(age, prenom) if (age >= 18) \
                    printf("Tu est majeur %s!", prenom); \
                    else \
                    printf("t un mome!") ;

int main(int argc, char *argv[])
{
    MAJEUR(27,"Robert")

    printf("fichier compile le %s", __DATE__ );

    return 0;
}
