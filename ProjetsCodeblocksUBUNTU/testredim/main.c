#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   int tab1[0] = {};
   int tab2[3] = {2,3,6};

   int i = 0;
    int taille = 3;
/*
   int redim(int tab1[],int taille){

    return tab1[taille];

   }
   redim(tab1,taille);*/

   for(i = 0;i < taille;i++){
        tab1[i] = tab2[i];
        printf("%d\n",tab1[i]);
   }




    return 0;
}
