#include <stdio.h>
#include <stdlib.h>

#define bool double
#define true 1
#define false 0

int main(int argc, char *argv[])
{
    int age = 0;
    char sexe = 0;
    double Himposable = true;
    double Fimposable = true;

    printf("Entrez votre age:");
    scanf("%d",&age);
    /*printf("\nEntrez votre sexe (f pour femme et m pour homme:");
    scanf("%c",&sexe);*/
    Fimposable = (age >= 18 &&  age <= 35 && sexe = "f"); /* En C avec type boolenn cr�� artificiellement pas de conditions
    compos�es avec des variable de caract�re et variable de nombre en m�me temps */
    Himposable = age >= 20 && age <= 40 /*&& sexe = "m"*/ ;

    if(Fimposable || Himposable)
    {
        printf("Vous etes imposable");
    }
    else
        {
        printf("non, pas imposable");
        }



    return 0;
}
