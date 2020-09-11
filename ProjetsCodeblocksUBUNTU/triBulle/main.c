#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i = 0;
    int t = 4;

    int tab[4] = {1, 3, 2, 4};
  void intervertir(int tab[], int t);
    for(i = 0 ; i < 4 ; i++)
    {
        if(tab[i] < tab[i + 1])
        {

        }
        else if(tab[i] == tab[i + 1])
        {

        }
        else if(tab[i] > tab[i + 1])
        {
            intervertir(&tab[i], t);
        }



    }
    return 0;


        void intervertir(int tab[], int t)
        {
            int v = 0, i = 0;
            do{
                *tab[i + 1] = v;
                *tab[i] = *tab[i + 1];
                v = *tab[i];
            } while (*tab[i] > *tab[i + 1]);

            for(i = 0 ; i < 4 ; i++)
            {
              printf("%d\n", tab[i]);
            }

        }

}
