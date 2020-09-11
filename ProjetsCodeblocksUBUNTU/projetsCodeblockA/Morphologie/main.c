#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[])
{
  int poids = 0, taille = 0, age = 0;

  printf("Veuillez entrez votre poids, taille en cm et age, pour connaitre votre\n\n type de morphologie!\n");
  scanf("%d", &poids);
  scanf("%d", &taille);
  scanf("%d", &age);

  if(poids <= 75 && taille <= 180 && age > 18)
  {
      printf("Vous etes mesomorphe, bravo c est les meilleurs, je plaisante!");
  }
    else if(poids <= 70 && taille <= 185 && age > 18)
    {
        printf("Vous etes ectomorphe");
    }
    else if(poids >= 80 && taille <= 160 && age > 18)
    {
        printf("Vous etes endomorphe");
    }



    return 0;
}




