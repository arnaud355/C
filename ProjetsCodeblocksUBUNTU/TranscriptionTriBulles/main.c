#include <stdio.h>
#include <stdlib.h>


#define TRUE = 1
#define FALSE = 0

void swap(int tab[], int tailleTab);

int main(int argc, char *argv[])
{
    int tab[4] = {5,8,3,2};

        swap(tab, 4);

    return 0;
}

void swap(int tab[], int tailleTab)
{
     int i = 0;
      int tmp;
    int en_desordre = 1;

        while(en_desordre)
        {
            en_desordre = 0;

            for(i = 0; i < 4; i++)
            {
                if(tab[i] > tab[i + 1])
                {
                     tmp = tab[i + 1];
                    tab[i] = tab[i + 1];
                    tmp = tab[i + 1];
                }
                en_desordre = 1;
                printf("%d\n", tab[i]);
            }
        }
}
