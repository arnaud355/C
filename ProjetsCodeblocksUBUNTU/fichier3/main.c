#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* fopen(const char *nomDuFichier, const char* modeOuverture);
int fclose(FILE* pointeurSurFichier);

int main(int argc, char *argv[])
{
  FILE* fichier = NULL;
  int age = 0;

  fichier = fopen("test.txt","w");

  if(fichier != NULL)
  {
    printf("Quel age avez-vous?");
    scanf("%d", &age);

    fprintf(fichier, "le monsieur qui utilise le programme, il a %d ans", age);
    fclose(fichier);


  }
    return 0;
}
