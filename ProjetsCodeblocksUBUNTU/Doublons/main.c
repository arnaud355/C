#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int tab[5] = {4,2,4,3,4}, i = 0, tabu[5] = {0};



    for(i = 0; i < 5; i++)
    {


        if(tabu[i] != tab[i]);
        {
          tabu[i] = tab[i];
        }

            if(tabu[i] = tab[i])
            {
                tabu[i] = 0;

                printf("%d\n", tabu[i]);
            }



    }
    return 0;

}
