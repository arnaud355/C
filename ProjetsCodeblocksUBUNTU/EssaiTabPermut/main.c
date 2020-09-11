#include <stdio.h>
#include <stdlib.h>

#define TRUE = 1
#define FALSE = 0

void swap(int tab[], int tailletableau );

int main(int argc, char *argv[])
{
    int tab[4] = {5,8,3,2};

    swap(tab, 4);


    return 0;
}

void swap(int tab[], int tailletableau)
{
int temp = 0, i = 0;
for(i = 0; i < tailletableau; i++)
{
if(tab[i] > tab[i + 1])
{
temp = tab[i];
tab[i] = tab[i + 1];
tab[i + 1] = temp;
}
printf("%d\n", tab[i]);
}

}
