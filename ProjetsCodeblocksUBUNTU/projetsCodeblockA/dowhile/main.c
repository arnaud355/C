#include <stdio.h>
#include <stdlib.h>

int main()
{
    int compteur = 0;

    do                     // c est la meme chose que la boucle while mais elle s excute au moins une fois
    {
        printf("Salut les zeros\n");
        compteur++;
    } while (compteur < 10);

    return 0;
}
