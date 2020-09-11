#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main(int argc, char *argv[])
{
   FILE* fichier = NULL;
    int CaractereActuel = 0;
   fichier = fopen("testLecture","r");

   if(fichier != NULL)
   {
    do{
    CaractereActuel = fgetc(fichier);
    printf("%c", CaractereActuel);
    } while (CaractereActuel != EOF);

    fclose(fichier);
   }
    return 0;
}
