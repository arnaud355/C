#include <stdio.h>
#include <stdlib.h>

int main()
{
int cible;
scanf("%d", &cible);
if(cible >= 0)
{
    int valeur = 1;
    while (cible)
    {
        printf("%d", valeur);
        valeur = valeur + 1;
    }
}
else
{
    printf("Ne rien faire");
}




    return 0;
}
