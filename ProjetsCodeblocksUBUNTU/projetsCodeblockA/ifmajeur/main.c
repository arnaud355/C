#include <stdio.h>
#include <stdlib.h>

int main()
{
    int age = 18, majeur = age >= 18;

    if(majeur)
    {
      printf("Vous etes majeur! \n");
    }

    else
    {
        printf("Ah non vous etes mineur \n");
    }

    return 0;
}
