#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>

void pause();

int main(int argc, char *argv[]){


    SDL_Init(SDL_INIT_VIDEO); //Démarrage de la SDL(ici: chargement système video)
    SDL_Surface *ecran = NULL; //Le pointeur qui va stocker la surface de l'écran
    SDL_Surface *lignes[256] = {NULL}; /*tableau de pointeurs qui va stocker la surface d'une ligne dans l'écran
    et ceci 256 fois, chaque ligne est à NULL*/
    int i = 0;

    SDL_Rect position; //variable de type SDL_Rect, c'est une structure qui contient des sous-variables servant aux coordonnées

    ecran =  SDL_SetVideoMode(640,256,32, SDL_HWSURFACE);//On tente d'ouvrir une fenêtre, 256 de hauteur pour correspondre aux lignes
    if(ecran == NULL){ //Si l'ouverture a echoué, on le note et on l'arrête
        fprintf(stderr,"Erreur d'initialisation de la SDL: %s\n", SDL_GetError());//ecriture de l'erreur
        exit(EXIT_FAILURE);
    }
//La SDL est chargée. On peut y mettre le contenu du programme
    for(i = 0; i < 256; i++){
        lignes[i] = SDL_CreateRGBSurface(SDL_HWSURFACE,640,1,32,0,0,0,0);/*On alloue à chaque ligne du tableau
        une largeur de 640 et 1 de hauteur, en 32 bits, les autres paramètres ne nous interesse pas*/
    }



for(i = 0; i < 256; i++){
       position.x = 0;//Les lignes commence tout à gauche (absicce à 0)
        position.y = i;//à chaque passage, on descend d'une ligne

     SDL_FillRect(lignes[i],NULL,SDL_MapRGB(ecran->format,i,i,i));/*remplissage de la ligne avec une couleur, deuxième paramètre
     à null pour indiquer qu'on prend toute la surface de la ligne*/
         SDL_BlitSurface(lignes[i],NULL,ecran,&position); /*On blitte (coller) notre surface rectangle sur l'écran,
         le deuxième paramètre est à null pour indiquer la taille de la surface à coller, comme on prend tous il faut mettre null
         ,il faut envoyer l'adresse de variable position*/

}
SDL_WM_SetCaption("Mon degrade avec SDL!",NULL);//Change le titre de la fenêtre, deuxième paramètre est le logo
      SDL_Flip(ecran); //Mise à jour de l'écran avec sa nouvelle couleur

        pause();//Mise en pause du programme

    SDL_FreeSurface(lignes[i]);//Libération de la surface
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


