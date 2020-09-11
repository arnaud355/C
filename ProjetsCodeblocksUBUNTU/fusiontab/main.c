#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define true 1
#define false 0
int main(int argc, char *argv[])
{
    int tabA[4] = {5,7,9,11};/*Le but de la fusion de tableaux est de ranger deux tableaux déjà triés dans un troisième, et en
    les mettant à nouveau trié dans ce troisième tableau */
    int tabB[3] = {6,8,10};
    int tabC[0] = {};

    int tailleA = 4, tailleB = 3, i = 0;

    char afini = false;
    char bfini = false;
    int ia = 0, ib = 0,ic = -1;

        int redim(int tabC[],int ic) {

            return tabC[ic];
        }

    while(!(afini) || !(bfini)) {

        ic = ic + 1;
        redim(tabC, ic);

        if(afini || tabA[ia] > tabB[ib]){
            tabC[ic] = tabB[ib];
            ib = ib + 1;
            bfini = ib >= tailleB;
        }
        else {
            tabC[ic] = tabA[ia];
            ia = ia + 1;
            afini = ia >= tailleA;
        }
    }
    for(i = 0; i < ic; i++){
        printf("%d\n",tabC[i]);
    }

    return 0;
}
