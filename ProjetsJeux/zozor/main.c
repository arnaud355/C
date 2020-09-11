#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>


int main(int argc, char *argv[]){


    SDL_Surface *ecran = NULL;//Le type SDL_Surface à plusieurs sous-variable qui attendent des formes rectangulaires, images.
    SDL_Surface *zozor = NULL; //Le pointeur qui va stocker la surface de l'écran ou de l'image ou rectangle de type SDL_Surface
    SDL_Event event; //Cette variable servira plus tard à gérer les évenements, elle est de type évenement


    SDL_Rect positionZozor;


    int continuer = 1;/*On crée un booléen, qu'on met à 1, qu'on va mettre en condition dans une boucle pour qu'elle
    continue à tourner tant que l'événement voulu n'est pas arrivé*/
    SDL_Init(SDL_INIT_VIDEO); //Démarrage de la SDL(ici: chargement système video)

    ecran =  SDL_SetVideoMode(640,480,32, SDL_HWSURFACE | SDL_FULLSCREEN | SDL_DOUBLEBUF);//On tente d'ouvrir une fenêtre et en pleine écran
    if(ecran == NULL){ //Si l'ouverture a echoué, on le note et on l'arrête
        fprintf(stderr,"Erreur d'initialisation de la SDL: %s\n", SDL_GetError());//ecriture de l'erreur
        exit(EXIT_FAILURE);
    }
    //La SDL est chargée. On peut y mettre le contenu du programme
    zozor = SDL_LoadBMP("zozor.bmp");
    SDL_SetColorKey(zozor,SDL_SRCCOLORKEY,SDL_MapRGB(zozor->format,0,0,255));//rend tranparent

    positionZozor.x = ecran->w / 2 - zozor->w / 2;
    positionZozor.y = ecran->h / 2 - zozor->h / 2;/*On centre Zozor uniquement après avoir chargé les surfaces ecran et zozor
    car dans les coordonnées ont a besoin de pointeurs, qui dans ecran et zozor, récupère la largeur et longueur inscrites
    dans w(width) et h (height)*/

      SDL_WM_SetCaption("Gestion des evenements en SDL!",NULL);//Change le titre de la fenêtre, deuxième paramètre est le logo

    SDL_EnableKeyRepeat(10,10);//Permet d'activer répétitions des touches sans avoir à appuyer régulièrement dessus

    while(continuer){//Tant que la variable ne vaut pas 0 on continue
        /*traitement des événements, on a une boucle infini que si on met la variable continuer à 0*/
        SDL_WaitEvent(&event); /*La fonction waitevent attend qu'un evenement se produise, le processeur est mis en pause,
        elle attend un pointeur sur une variable de type SDL_Event,car il peut y avoir surement plusieurs évenements d'affilés*/
        switch(event.type){ //On analyse le type d'évenement reçu grâce à un switch (ou un if), le type de l'évenment se trouve dans la ssous-variable event.type
          case SDL_QUIT:/*Si l'évenement est de type SDL_QUIT c'est que l'utilisateur veut quiter, on sort d la boucl avec 0 à continuer
               l'evenement SDL_QUIT est une constante de sdl, chaque évenement à sa constante*/
                continuer = 0;
              break;
          case SDL_MOUSEBUTTONUP://Cas où je clique sur l'un des boutons de la souris
            if(event.button.button == SDL_BUTTON_RIGHT){/*Cette sous-sous variable de event de type SDL_Event
            indique la nature du clic, là cas où c'est le clic droit de la souris */
                continuer = 0;
            }
            else if(event.button.button == SDL_BUTTON_LEFT){
                positionZozor.x = event.button.x;//event.button.x indique les coordonnées au moment du clic (là du cllic gauche)
                positionZozor.y = event.button.y;
            }
            break;
          case SDL_MOUSEMOTION://Cas où la souris est en mouvement
            positionZozor.x = event.motion.x;//Indique les coordonnées de la souris à chaque mouvements
            positionZozor.y = event.motion.y;
            break;
        /*
            if((event.active.state && SDL_APPMOUSEFOCUS) == SDL_APPMOUSEFOCUS){//event.active.gain est une combinaison de flag
                indiquant l'évenement qui s'est produit,il est combiné avec l'évenement en question, sous booleen
                if(event.active.gain == 0){//event.active.gain indique perte ou gain, par exemple là sorti de la souris de l'écran, perte
                    positionZozor.x--;
                }
                else if(event.active.gain == 1){
                    positionZozor.x++;
                }
            }*/
           case SDL_KEYDOWN://Cas où l'événement est une touche enfoncé du clavier
               switch(event.key.keysym.sym){/*La sous-sous-sous variable de event de type SDL_Event, à ce chemin indique la
                nature de la touche touchée, pour chaque touche du clavier est associé une constance qui renferme
                une valeur ASCII(un symbole, chiffre...)*/

                case SDLK_ESCAPE:
                    continuer = 0;
                    break;
                case SDLK_UP:  //fleche du haut
                    positionZozor.y--;
                    break;
                case SDLK_DOWN:  //fleche du bas
                    positionZozor.y++;
                    break;
                case SDLK_LEFT:   //fleche de gauche
                    positionZozor.x--;
                    break;
                case SDLK_RIGHT:  //fleche de droite
                    positionZozor.x++;
                    break;
                }
                break;
        }
        //On efface l'écran
        SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
        //On place zozor à sa nouvelle position
        SDL_BlitSurface(zozor,NULL,ecran,&positionZozor);
        //On met à jour l'affichage
        SDL_Flip(ecran);
    }


    SDL_FreeSurface(zozor);
    SDL_Quit(); //Arrêt de la SDL(Libération de la mémoire)

return EXIT_SUCCESS;
}



