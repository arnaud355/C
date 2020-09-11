#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>

void pause();

int main(int argc, char *argv[]){


    SDL_Init(SDL_INIT_VIDEO); //D�marrage de la SDL(ici: chargement syst�me video)
    SDL_Surface *ecran = NULL; //Le pointeur qui va stocker la surface de l'�cran
    SDL_Surface *rectangle = NULL; //Le pointeur qui va stocker la surface du rectangle dans l'�cran

    SDL_Rect position; //variable de type SDL_Rect, c'est une structure qui indique qui contient des coordonn�es

    ecran =  SDL_SetVideoMode(640,480,32, SDL_HWSURFACE);//On tente d'ouvrir une fen�tre
    if(ecran == NULL){ //Si l'ouverture a echou�, on le note et on l'arr�te
        fprintf(stderr,"Erreur d'initialisation de la SDL: %s\n", SDL_GetError());//ecriture de l'erreur
        exit(EXIT_FAILURE);
    }
    //La SDL est charg�e. On peut y mettre le contenu du programme


    rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE,220,180,32,0,0,0,0);//Cr�ation du rectangle, soit la surface
      SDL_WM_SetCaption("Ma super fenetre!",NULL);//Change le titre de la fen�tre, deuxi�me param�tre est le logo

      //Coloration de la surface ecran en bleu-vert, le deuxi�me param�tre, null, indique la surface � colorier, si null, alors toute la surface
      SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,17,206,112));

    /*On centre le rectangle, on calcule la longueur de l'�cran est on divise par deux, puis soustraction par la moiti�
    du rectangle, on fait cela pour l'abscisse et l'ordonn�e*/
         position.x = (640 / 2) - (220 / 2);
         position.y = (480 / 2) - (180 / 2);
         SDL_FillRect(rectangle,NULL,SDL_MapRGB(ecran->format,255,255,255));//remplissage de rectangle avec du blanc
         SDL_BlitSurface(rectangle,NULL,ecran,&position); //On blitte (coller) notre surface rectangle sur l'�cran, il faut envoyer l'adresse de variable position

      SDL_Flip(ecran); //Mise � jour de l'�cran avec sa nouvelle couleur

        pause();//Mise en pause du programme

    SDL_FreeSurface(rectangle);//Lib�ration de la surface
    SDL_Quit(); //Arr�t de la SDL(Lib�ration de la m�moire)

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

