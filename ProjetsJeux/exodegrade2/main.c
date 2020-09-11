#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>

void pause();

int main(int argc, char *argv[]){


    SDL_Init(SDL_INIT_VIDEO); //D�marrage de la SDL(ici: chargement syst�me video)
    SDL_Surface *ecran = NULL; //Le pointeur qui va stocker la surface de l'�cran
    SDL_Surface *lignes[640] = {NULL}; /*tableau de pointeurs qui va stocker la surface d'une ligne dans l'�cran
    et ceci 480 fois, chaque ligne est � NULL*/

    int i = 0;
    int r = 0, g = 0, b = 0;

    SDL_Rect position; //variable de type SDL_Rect, c'est une structure qui contient des sous-variables servant aux coordonn�es

    ecran =  SDL_SetVideoMode(640,480,32, SDL_HWSURFACE);//On tente d'ouvrir une fen�tre, 512 de hauteur pour correspondre aux lignes
    if(ecran == NULL){ //Si l'ouverture a echou�, on le note et on l'arr�te
        fprintf(stderr,"Erreur d'initialisation de la SDL: %s\n", SDL_GetError());//ecriture de l'erreur
        exit(EXIT_FAILURE);
    }
//La SDL est charg�e. On peut y mettre le contenu du programme
    for(i = 0; i < 640; i++){
        lignes[i] = SDL_CreateRGBSurface(SDL_HWSURFACE,1,480,32,0,0,0,0);/*On alloue � chaque ligne du tableau
        une largeur de 640 et 1 de hauteur, en 32 bits, les autres param�tres ne nous interesse pas*/
    }


r = 53,g = 152,b = 33;

for(i = 0; i < 640; i++){
       position.x = i;
        position.y = 0;//� chaque passage, on descend d'une ligne

     SDL_FillRect(lignes[i],NULL,SDL_MapRGB(ecran->format,r,g,b));/*remplissage de la ligne avec une couleur, deuxi�me param�tre
     � null pour indiquer qu'on prend toute la surface de la ligne*/
         SDL_BlitSurface(lignes[i],NULL,ecran,&position); /*On blitte (coller) notre surface rectangle sur l'�cran,
         le deuxi�me param�tre est � null pour indiquer la taille de la surface � coller, comme on prend tous il faut mettre null
         ,il faut envoyer l'adresse de variable position*/
   if(r >= 0 ){
        r = r - 1;
   }
    if(g >= 0 ){
         g = g - 1;
   }
    if(b >= 0 ){
        b = b - 1;
   }


}


SDL_WM_SetCaption("Mon degrade avec SDL!",NULL);//Change le titre de la fen�tre, deuxi�me param�tre est le logo
      SDL_Flip(ecran); //Mise � jour de l'�cran avec sa nouvelle couleur

        pause();//Mise en pause du programme

    SDL_FreeSurface(lignes[i]);//Lib�ration de la surface

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






