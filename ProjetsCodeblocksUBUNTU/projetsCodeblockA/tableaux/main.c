#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int tableau[4], i = 0;

    tableau[0] = 45;
    tableau[1] = 52;
    tableau[2] = 58;
    tableau[3] = 65;

    for (i = 0; i < 4; i++ )
    {
        printf("%d\n", tableau[i]);
    }


    return 0;
}
