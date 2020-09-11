#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   int tab[4] = {4,6,5,2}, i = 0, Valmin = 0;




   if(tab[i] > Valmin)
   {
      Valmin = tab[i];
   }


  if(tab[i + 1] > Valmin)
   {
         Valmin = tab[i + 1];
   }
    printf("%d\n", Valmin);



    return 0;
}
