#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int tab[4] = {5,3,6,4}, i = 0, v = 3, c;

    for(i = 0; i < 4; i++)
    {
        for(v = 3; v >= 0; v--)
    {
            if(tab[i] > tab[v])
            {
               c = tab[v];
                tab[i] = tab[v];
                c = tab[i];
            }

    }



        printf("%d",c);
    }

    return 0;
}
