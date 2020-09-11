#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

 char lireCaractere();

int main(int argc, char *argv[])
{
  char maLettre;
  maLettre = lireCaractere();

    printf("%c", maLettre);

    return 0;
}

char lireCaractere()
{
    char caractere = 0;
    caractere = getchar();
    caractere = toupper(caractere);

    while(getchar() != '\n');




    return caractere;


}
