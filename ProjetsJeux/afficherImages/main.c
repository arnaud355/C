#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>//Inclusion du header de SDL_image

void pause();

int main(int argc, char *argv[]){



    SDL_Surface *ecran = NULL; //Le pointeur qui va stocker la surface de l'écran
    SDL_Surface *imageDeFond = NULL;//Le pointeur qui va stocker l'image
    SDL_Surface *zozor = NULL, *sapin = NULL;//comme pour les autres types ont peut aussi faire: SDL_Surface *ecran = NULL, *imageDeFond = NULL...
    SDL_Rect positionFond, positionZozor, positionSapin; //variable de type SDL_Rect, c'est une structure qui indique, contient des coordonnées

    positionFond.x = 0;
    positionFond.y = 0;
    positionZozor.x = 500;
    positionZozor.y = 260;
    positionSapin.x = 200;
    positionSapin.y = 450;

    SDL_Init(SDL_INIT_VIDEO); //Démarrage de la SDL(ici: chargement système video)

    SDL_WM_SetIcon(SDL_LoadBMP("sdl_icone.bmp"), NULL);//Chargement de l'icone AVANT SDL_SetVideoMode

    ecran =  SDL_SetVideoMode(800,600,32, SDL_HWSURFACE);//On tente d'ouvrir une fenêtre
    if(ecran == NULL){ //Si l'ouverture a echoué, on le note et on l'arrête
        fprintf(stderr,"Erreur d'initialisation de la SDL: %s\n", SDL_GetError());//ecriture de l'erreur
        exit(EXIT_FAILURE);
    }
    //La SDL est chargée. On peut y mettre le contenu du programme

      SDL_WM_SetCaption("Chargement d'images en SDL",NULL);//Change le titre de la fenêtre, deuxième paramètre est le logo

        imageDeFond = SDL_LoadBMP("lac_en_montagne.bmp");/*On charge une image Bitmap dans une surface, la taille va être
        allouée dynamiquement (largeur * longueur)selon l'image, comme le ferait la fonction sdlcreateRGBSurface pour un
        rectangle, et en plus la fonction SDL_LoadBMP va remplir pixel par pixel le contenu nouvellement crée avec l'image,
        comme le ferait RectFill... pour un rectangle, donc fonction deux en un(calcule taille et remplis pixel par pixel)*/
         SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond); //On blitte (coller) notre image sur l'écran, il faut envoyer l'adresse de variable position

        /*Chargement et blittage de Zozor sur la scène*/
        zozor = SDL_LoadBMP("zozor.bmp");
        /*On rend le bleu derrière Zozor transparent: on utilise pour cela la fonction SDL_SetColorKey, elle prend en
        premier paramètre l'image à rendre transparente, ensuite on active la transparence avec SDL_SRCCOLORKEY ou 0
        pour le désactiver, ensuite on récupère la couleur à rendre transparente, on récupère dans le type de zozor
        soit SDL_Surface la couleur qui l'encode, soit en 32 bits(contient des milliards de pixel) puis la rgb de la
        couleur*/
        SDL_SetColorKey(zozor,SDL_SRCCOLORKEY,SDL_MapRGB(zozor->format,0,0,255));

        /*Transparence Alpha moyenne (128): permet de réaliser un fondu de l'image et son fond, compatible avec SDL_SetColorKey,
        le deuxième parmaètre gère l'opacité, de 0 à 255, 0 transparent, 255 opaque, à 128 c'est la moitié.
        Son utilité est que cette transparence est la plus optimisée, rapide sous sdl, utilse si beaucoup de transparence
        utilisée*/
        SDL_SetAlpha(zozor,SDL_SRCALPHA,128);

        /*On blitte l'image maintenant transparente sur le fond:*/
        SDL_BlitSurface(zozor,NULL,ecran,&positionZozor);

        /*Chargement d'un PNG avec IMG_load, celui-ci est automatiquement rendu transparent car les informations de
        transparence sont codées à l'intérieur du fichier PNG*/
        sapin = IMG_Load("sapin.png");/*La fonction IMG_load est inclue dans le header SDL_image.h et prend en compte
        tous les formats d'images, y compris les .bmp, mais avant il suffit d inclure le header SDL_image.h*/
        SDL_BlitSurface(sapin,NULL,ecran,&positionSapin);

      SDL_Flip(ecran); //Mise à jour de l'écran avec sa nouvelle couleur

        pause();//Mise en pause du programme

    SDL_FreeSurface(imageDeFond);//On libère la surface
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

