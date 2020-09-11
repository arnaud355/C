#include <stdio.h>
#include <stdlib.h>

 void triplePointeur(int *pointeurSurNombre);

int main(int argc, char *argv[])
{
   int nombre = 534;

    triplePointeur(&nombre);
    printf("%d", nombre);

    return 0;

}
void triplePointeur(int *pointeurSurNombre)
{
    *pointeurSurNombre *= 3;
}
