#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>

void pause();

int main(int argc, char *argv[]){


    SDL_Init(SDL_INIT_VIDEO); //D�marrage de la SDL(ici: chargement syst�me video)
    SDL_Surface *ecran = NULL; //Le pointeur qui va stocker la surface de l'�cran
    SDL_Event event; //Cette variable servira plus tard � g�rer les �venements, elle est de type �venement

    int continuer = 1; /*On cr�e un bool�en, qu'on met � 1, qu'on va mettre en condition dans une boucle pour qu'elle
    continue � tourner tant que l'�v�nement voulu n'est pas arriv�*/

    ecran =  SDL_SetVideoMode(640,480,32, SDL_HWSURFACE | SDL_FULLSCREEN);//On tente d'ouvrir une fen�tre et en pleine �cran
    if(ecran == NULL){ //Si l'ouverture a echou�, on le note et on l'arr�te
        fprintf(stderr,"Erreur d'initialisation de la SDL: %s\n", SDL_GetError());//ecriture de l'erreur
        exit(EXIT_FAILURE);
    }
    //La SDL est charg�e. On peut y mettre le contenu du programme

      SDL_WM_SetCaption("Gestion des evenements en SDL!",NULL);//Change le titre de la fen�tre, deuxi�me param�tre est le logo

    while(continuer){//Tant que la variable ne vaut pas 0 on continue
        /*traitement des �v�nements, on a une boucle infini que si on met la variable continuer � 0*/
        SDL_WaitEvent(&event); /*La fonction waitevent attend qu'un evenement se produise, le processeur est mis en pause,
        elle attend un pointeur sur une variable de type SDL_Event,car il peut y avoir surement plusieurs �venements d'affil�s*/
        switch(event.type){ //On analyse le type d'�venement re�u gr�ce � un switch (ou un if), le type de l'�venment se trouve dans la ssous-variable event.type
            case SDL_QUIT://Si l'�venement est de type SDL_QUIT c'est que l'utilisateur veut quiter, on sort d la boucl avec 0 � continuer
               //l'evenement SDL_QUIT est une constante de sdl, chaque �venement � sa constante
                continuer = 0;
                break;
            case SDL_KEYDOWN://Cas o� l'�v�nement est une touche enfonc� du clavier
                switch(event.key.keysym.sym)/*La sous-sous-sous variable de event de type SDL_Event, � ce chemin indique la
                nature de la touche touch�e, pour chaque touche du clavier est associ� une constance qui renferme
                une valeur ASCII(un symbole, chiffre...)*/
                {
                case SDLK_ESCAPE:
                    continuer = 0;
                    break;
                }
                break;
        }
    }

    SDL_Quit(); //Arr�t de la SDL(Lib�ration de la m�moire)

return EXIT_SUCCESS;
}



