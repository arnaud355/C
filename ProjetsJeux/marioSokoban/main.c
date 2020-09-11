//Rôle: Menu du jeu

#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>

#include "constantes.h"
#include "jeu.h"
#include "editeur.h"

int main(int argc, char *argv[]){



    SDL_Surface *ecran = NULL; //Le pointeur qui va stocker la surface de l'écran
    SDL_Surface *menu = NULL; //Le pointeur qui va stocker la surface du rectangle dans l'écran
    SDL_Rect positionMenu;
    SDL_Event event;

    int continuer = 1;

    SDL_Init(SDL_INIT_VIDEO); //Démarrage de la SDL(ici: chargement système video)

    SDL_WM_SetIcon(IMG_Load("caisse.jpg"),NULL);//L'icône doit être chargée avant SDL_SetVideoMode
    ecran =  SDL_SetVideoMode(LARGEUR_FENETRE,HAUTEUR_FENETRE,32, SDL_HWSURFACE | SDL_DOUBLEBUF);//On tente d'ouvrir une fenêtre
    if(ecran == NULL){ //Si l'ouverture a echoué, on le note et on l'arrête
        fprintf(stderr,"Erreur d'initialisation de la SDL: %s\n", SDL_GetError());//ecriture de l'erreur
        exit(EXIT_FAILURE);
    }
    SDL_WM_SetCaption("Mario Sokoban",NULL);//Donne un titre
    //La SDL est chargée. On peut y mettre le contenu du programme

    menu = IMG_Load("menu.jpg");
    positionMenu.x = 0;
    positionMenu.y = 0;

    while(continuer){


         SDL_WaitEvent(&event);
        switch(event.type){
            case SDL_QUIT:
            continuer = 0;
            break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym){
                case SDLK_ESCAPE://Veut arrêter de jouer
                    continuer = 0;
                    break;
                case SDLK_KP1://Demande de jouer
                    jouer(ecran);//La fonction jouer recupère un pointeur sur ecran
                    break;
                case SDLK_KP2://Demande l'éditeur de niveaux
                   editeur(ecran);
                    break;
                   /* arret = editeur(ecran,arret);
                    if(arret == 0){
                        continuer = 0;*/
                    }
                    break;
                }

        SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,155,146,23));//remplit la surface ecran de noir
        SDL_BlitSurface(menu,NULL,ecran,&positionMenu); //colle la surface menu sur l'ecran
        SDL_Flip(ecran); //met à jour l'écran

        }



    SDL_FreeSurface(menu);//Libération de la surface
    SDL_Quit(); //Arrêt de la SDL(Libération de la mémoire)

return EXIT_SUCCESS;
}



