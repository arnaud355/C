#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ChoixMenu;

    printf("==Menu== \n\n");
    printf("1.royal\n");
    printf("2.mcdeluxe\n");
    printf("3.mcarno\n");
    printf("4.mcarthur\n");
    printf("\n Votre choix?\n");
    scanf("%d", &ChoixMenu);



    switch (ChoixMenu)
    {
        case 1:
        printf("vous avez choisi le royal");
        break;

        case 2:
        printf("vous avez choisi mcdeluxe");
        break;

        case 3:
        printf("c'est le meilleur choix!");
        break;

        case 4:
        printf("C'est tres marin");
        break;

        default:
        printf("Vous n avez rien choisi andouille");
        break;
    }

        printf("\n\n");

    return 0;
}
