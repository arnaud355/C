#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define COUCOU() printf("Coucou Hibou!");
#define RACONTER_SA_VIE() printf("Salut, je m appelle Brice\n"); \
                            printf("Je viens de Nice\n");\
                            printf("J aime la glisse");
int main(int argc, char *argv[])
{

    COUCOU()
    RACONTER_SA_VIE()

    return 0;
}
