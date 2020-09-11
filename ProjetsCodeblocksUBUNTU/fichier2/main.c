#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"


int main(int argc, char *argv[])
{
    FILE* fichier = NULL;

    fichier = fopen("test.txt","w");

    if(fichier != NULL)
    {
        fputs("Salut les zeros BOBO\nComment allez-vous ?", fichier);
        fclose(fichier);
    }

    return 0;
}
