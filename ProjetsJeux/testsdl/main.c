#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>

void pause();

int main(int argc, char *argv[]){


    SDL_Init(SDL_INIT_VIDEO); //Démarrage de la SDL(ici: chargement système video)
    SDL_Surface *ecran = NULL; //Le pointeur qui va stocker la surface de l'écran
    SDL_Surface *rectangle = NULL; //Le pointeur qui va stocker la surface du rectangle dans l'écran

    SDL_Rect position; //variable de type SDL_Rect, c'est une structure qui indique qui contient des coordonnées

    ecran =  SDL_SetVideoMode(640,480,32, SDL_HWSURFACE);//On tente d'ouvrir une fenêtre
    if(ecran == NULL){ //Si l'ouverture a echoué, on le note et on l'arrête
        fprintf(stderr,"Erreur d'initialisation de la SDL: %s\n", SDL_GetError());//ecriture de l'erreur
        exit(EXIT_FAILURE);
    }
    //La SDL est chargée. On peut y mettre le contenu du programme


    rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE,220,180,32,0,0,0,0);//Création du rectangle, soit la surface
      SDL_WM_SetCaption("Ma super fenetre!",NULL);//Change le titre de la fenêtre, deuxième paramètre est le logo

      //Coloration de la surface ecran en bleu-vert, le deuxième paramètre, null, indique la surface à colorier, si null, alors toute la surface
      SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,17,206,112));

    /*On centre le rectangle, on calcule la longueur de l'écran est on divise par deux, puis soustraction par la moitié
    du rectangle, on fait cela pour l'abscisse et l'ordonnée*/
         position.x = (640 / 2) - (220 / 2);
         position.y = (480 / 2) - (180 / 2);
         SDL_FillRect(rectangle,NULL,SDL_MapRGB(ecran->format,255,255,255));//remplissage de rectangle avec du blanc
         SDL_BlitSurface(rectangle,NULL,ecran,&position); //On blitte (coller) notre surface rectangle sur l'écran, il faut envoyer l'adresse de variable position

      SDL_Flip(ecran); //Mise à jour de l'écran avec sa nouvelle couleur

        pause();//Mise en pause du programme

    SDL_FreeSurface(rectangle);//Libération de la surface
    SDL_Quit(); //Arrêt de la SDL(Libération de la mémoire)

return EXIT_SUCCESS;
}

void pause(){
    int continuer = 1;
    SDL_Event event;

    while(continuer){
        SDL_WaitEvent(&event);
        switch(event.type){
            case SDL_QUIT:
            continuer = 0;
        }
    }
}

