#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>

void pause();

int main(int argc, char *argv[]){


    SDL_Init(SDL_INIT_VIDEO); //Démarrage de la SDL(ici: chargement système video)
    SDL_Surface *ecran = NULL; //Le pointeur qui va stocker la surface de l'écran
    SDL_Event event; //Cette variable servira plus tard à gérer les évenements, elle est de type évenement

    int continuer = 1; /*On crée un booléen, qu'on met à 1, qu'on va mettre en condition dans une boucle pour qu'elle
    continue à tourner tant que l'événement voulu n'est pas arrivé*/

    ecran =  SDL_SetVideoMode(640,480,32, SDL_HWSURFACE | SDL_FULLSCREEN);//On tente d'ouvrir une fenêtre et en pleine écran
    if(ecran == NULL){ //Si l'ouverture a echoué, on le note et on l'arrête
        fprintf(stderr,"Erreur d'initialisation de la SDL: %s\n", SDL_GetError());//ecriture de l'erreur
        exit(EXIT_FAILURE);
    }
    //La SDL est chargée. On peut y mettre le contenu du programme

      SDL_WM_SetCaption("Gestion des evenements en SDL!",NULL);//Change le titre de la fenêtre, deuxième paramètre est le logo

    while(continuer){//Tant que la variable ne vaut pas 0 on continue
        /*traitement des événements, on a une boucle infini que si on met la variable continuer à 0*/
        SDL_WaitEvent(&event); /*La fonction waitevent attend qu'un evenement se produise, le processeur est mis en pause,
        elle attend un pointeur sur une variable de type SDL_Event,car il peut y avoir surement plusieurs évenements d'affilés*/
        switch(event.type){ //On analyse le type d'évenement reçu grâce à un switch (ou un if), le type de l'évenment se trouve dans la ssous-variable event.type
            case SDL_QUIT://Si l'évenement est de type SDL_QUIT c'est que l'utilisateur veut quiter, on sort d la boucl avec 0 à continuer
               //l'evenement SDL_QUIT est une constante de sdl, chaque évenement à sa constante
                continuer = 0;
                break;
            case SDL_KEYDOWN://Cas où l'événement est une touche enfoncé du clavier
                switch(event.key.keysym.sym)/*La sous-sous-sous variable de event de type SDL_Event, à ce chemin indique la
                nature de la touche touchée, pour chaque touche du clavier est associé une constance qui renferme
                une valeur ASCII(un symbole, chiffre...)*/
                {
                case SDLK_ESCAPE:
                    continuer = 0;
                    break;
                }
                break;
        }
    }

    SDL_Quit(); //Arrêt de la SDL(Libération de la mémoire)

return EXIT_SUCCESS;
}



