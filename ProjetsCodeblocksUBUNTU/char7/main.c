#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* strpbrk(const char* chaine, const char *lettreARechercher);

int main(int argc, char *argv[])
{
  char *suitechaine;                                /*ou char chaine[] = "Texte de test"; et on met chaine dans
                                                    la fonction.*/

  suitechaine = strpbrk("Texte de tests", "xds");

  if(suitechaine != NULL)
  {
    printf("Voici la fin de la chaine a partir du premier des caracteres trouves: %s",suitechaine);

  }
    return 0;
}
