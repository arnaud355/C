#include <stdio.h>
#include <stdlib.h>


void swap(int tab[], int tailleTab);

int main(int argc, char *argv[])
{
    int tab[4] = {3,4,2,1};


    swap(tab,4);
    return 0;
}

void swap(int tab[],int tailleTab)
{
int i = 0, tmp = 0;

    for(i = 0; i < 4; i++)
    {


     if(tab[i] > tab[i + 1])
     {
        tmp = tab[i];
        tab[i] = tab[i + 1];
        tab[i + 1] = tmp;
    }


    }
    for(i = 0; i < 3; i++)
    {
         printf("%d",tab[i]);
    }




}
