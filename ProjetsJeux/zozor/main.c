#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>


int main(int argc, char *argv[]){


    SDL_Surface *ecran = NULL;//Le type SDL_Surface � plusieurs sous-variable qui attendent des formes rectangulaires, images.
    SDL_Surface *zozor = NULL; //Le pointeur qui va stocker la surface de l'�cran ou de l'image ou rectangle de type SDL_Surface
    SDL_Event event; //Cette variable servira plus tard � g�rer les �venements, elle est de type �venement


    SDL_Rect positionZozor;


    int continuer = 1;/*On cr�e un bool�en, qu'on met � 1, qu'on va mettre en condition dans une boucle pour qu'elle
    continue � tourner tant que l'�v�nement voulu n'est pas arriv�*/
    SDL_Init(SDL_INIT_VIDEO); //D�marrage de la SDL(ici: chargement syst�me video)

    ecran =  SDL_SetVideoMode(640,480,32, SDL_HWSURFACE | SDL_FULLSCREEN | SDL_DOUBLEBUF);//On tente d'ouvrir une fen�tre et en pleine �cran
    if(ecran == NULL){ //Si l'ouverture a echou�, on le note et on l'arr�te
        fprintf(stderr,"Erreur d'initialisation de la SDL: %s\n", SDL_GetError());//ecriture de l'erreur
        exit(EXIT_FAILURE);
    }
    //La SDL est charg�e. On peut y mettre le contenu du programme
    zozor = SDL_LoadBMP("zozor.bmp");
    SDL_SetColorKey(zozor,SDL_SRCCOLORKEY,SDL_MapRGB(zozor->format,0,0,255));//rend tranparent

    positionZozor.x = ecran->w / 2 - zozor->w / 2;
    positionZozor.y = ecran->h / 2 - zozor->h / 2;/*On centre Zozor uniquement apr�s avoir charg� les surfaces ecran et zozor
    car dans les coordonn�es ont a besoin de pointeurs, qui dans ecran et zozor, r�cup�re la largeur et longueur inscrites
    dans w(width) et h (height)*/

      SDL_WM_SetCaption("Gestion des evenements en SDL!",NULL);//Change le titre de la fen�tre, deuxi�me param�tre est le logo

    SDL_EnableKeyRepeat(10,10);//Permet d'activer r�p�titions des touches sans avoir � appuyer r�guli�rement dessus

    while(continuer){//Tant que la variable ne vaut pas 0 on continue
        /*traitement des �v�nements, on a une boucle infini que si on met la variable continuer � 0*/
        SDL_WaitEvent(&event); /*La fonction waitevent attend qu'un evenement se produise, le processeur est mis en pause,
        elle attend un pointeur sur une variable de type SDL_Event,car il peut y avoir surement plusieurs �venements d'affil�s*/
        switch(event.type){ //On analyse le type d'�venement re�u gr�ce � un switch (ou un if), le type de l'�venment se trouve dans la ssous-variable event.type
          case SDL_QUIT:/*Si l'�venement est de type SDL_QUIT c'est que l'utilisateur veut quiter, on sort d la boucl avec 0 � continuer
               l'evenement SDL_QUIT est une constante de sdl, chaque �venement � sa constante*/
                continuer = 0;
              break;
          case SDL_MOUSEBUTTONUP://Cas o� je clique sur l'un des boutons de la souris
            if(event.button.button == SDL_BUTTON_RIGHT){/*Cette sous-sous variable de event de type SDL_Event
            indique la nature du clic, l� cas o� c'est le clic droit de la souris */
                continuer = 0;
            }
            else if(event.button.button == SDL_BUTTON_LEFT){
                positionZozor.x = event.button.x;//event.button.x indique les coordonn�es au moment du clic (l� du cllic gauche)
                positionZozor.y = event.button.y;
            }
            break;
          case SDL_MOUSEMOTION://Cas o� la souris est en mouvement
            positionZozor.x = event.motion.x;//Indique les coordonn�es de la souris � chaque mouvements
            positionZozor.y = event.motion.y;
            break;
        /*
            if((event.active.state && SDL_APPMOUSEFOCUS) == SDL_APPMOUSEFOCUS){//event.active.gain est une combinaison de flag
                indiquant l'�venement qui s'est produit,il est combin� avec l'�venement en question, sous booleen
                if(event.active.gain == 0){//event.active.gain indique perte ou gain, par exemple l� sorti de la souris de l'�cran, perte
                    positionZozor.x--;
                }
                else if(event.active.gain == 1){
                    positionZozor.x++;
                }
            }*/
           case SDL_KEYDOWN://Cas o� l'�v�nement est une touche enfonc� du clavier
               switch(event.key.keysym.sym){/*La sous-sous-sous variable de event de type SDL_Event, � ce chemin indique la
                nature de la touche touch�e, pour chaque touche du clavier est associ� une constance qui renferme
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
        //On efface l'�cran
        SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
        //On place zozor � sa nouvelle position
        SDL_BlitSurface(zozor,NULL,ecran,&positionZozor);
        //On met � jour l'affichage
        SDL_Flip(ecran);
    }


    SDL_FreeSurface(zozor);
    SDL_Quit(); //Arr�t de la SDL(Lib�ration de la m�moire)

return EXIT_SUCCESS;
}



