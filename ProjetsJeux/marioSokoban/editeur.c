//R�le: fonction du jeu, chargement de sprites, d�cors
#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include "constantes.h"
#include "fichier.h"
#include "editeur.h"

void editeur(SDL_Surface *ecran){
SDL_Surface *mario = NULL;
SDL_Surface *mur = NULL, *caisse = NULL,*objectif = NULL;
SDL_Rect position;
SDL_Event event;



int continuer = 1,clicGaucheEnCours = 0,clicDroitEnCours = 0, arret = 1;
int objetActuel = MUR, i = 0, j = 0;
int carte[NB_BLOCS_LARGEUR][NB_BLOCS_HAUTEUR] = {0};
/*Les booleens clicGaucheEnCours et clicDroitEnCours permettent de m�moriser si un clic est en cours (bouton souris enfonc�)
cela nous permettra de poser des objets � l'�cran en laissant le bouton gauche de la souris enfonc� (sinon on est oblig�
de cliquer fr�n�tiquement avec la souris pour placer plusieurs fois le m�me objet � diff�rents endroits*/

//Chargement des objets et du niveau
mur = IMG_Load("mur.jpg");
caisse = IMG_Load("caisse.jpg");
objectif = IMG_Load("objectif.png");
mario = IMG_Load("mario_bas.gif");
/*Je ne charge qu'un seul Mario, en effet on ne va pas diriger Mario au clavier l�, on a juste besoin d'un sprite repr�sentant
la position de Mario au d�part.
La variable objetActuel retient lo'bjet s�lectionn� par l'utilisateur, par d�faut c'est un MUR, mais cela pourra �tre chang�
par l'utilisateur en appuyant sur 1,2,3 ou 4*/

    if(!chargerNiveau(carte)){
    exit(EXIT_FAILURE);
    }


//La boucle principale: les initialisations sont faites, on peut s'occuper de la boucle principale.
   while(continuer){
    switch(event.type){
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_MOUSEBUTTONDOWN:
            if(event.button.button == SDL_BUTTON_LEFT){
                //On met l'objet actuellement choisi (mur,caisse...) � l'endroit du clic
                carte[event.button.x / TAILLE_BLOC][event.button.y / TAILLE_BLOC] = objetActuel;
                clicGaucheEnCours = 1; //On retient qu'un bouton est enfonc�
            }
            else if(event.button.button == SDL_BUTTON_RIGHT){//clic droit pour effacer
                 carte[event.button.x / TAILLE_BLOC][event.button.y / TAILLE_BLOC] = VIDE;
                clicDroitEnCours = 1;
            }
            break;
        case SDL_MOUSEBUTTONUP: //On d�sactive le bool�en qui disait qu'un bouton �tait enfonc�
            if(event.button.button == SDL_BUTTON_LEFT)
                clicGaucheEnCours = 0;
            else if(event.button.button == SDL_BUTTON_RIGHT)
                clicDroitEnCours = 0;
            break;
        /*L'�venement MOUSEBUTTONUP sert simplement � remettre le bool�en � 0, on sait que le clic est termin� et donc qu'il
        ny'a plus de clic en cours*/
        case SDL_MOUSEMOTION:
            if(clicGaucheEnCours){//Si on d�place la souris et que le bouton gauche de la souris est enfonc�
                carte[event.button.x / TAILLE_BLOC][event.button.y / TAILLE_BLOC] = objetActuel;
            }
            else if(clicDroitEnCours){//Pareil pour le bouton droit de la souris
                carte[event.button.x / TAILLE_BLOC][event.button.y / TAILLE_BLOC] = VIDE;
            }
            break;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym){
            case SDLK_ESCAPE:
                continuer = 0;
                break;
            case SDLK_s:
                sauvegarderNiveau(carte);
                break;
            case SDLK_c:
                chargerNiveau(carte);
                break;
            case SDLK_1:
                objetActuel = MUR;
                break;
            case SDLK_2:
                objetActuel = CAISSE;
                break;
                   case SDLK_3:
                objetActuel = OBJECTIF;
                break;
                   case SDLK_4:
                objetActuel = MARIO;
                break;
            }
            break;
    }
   }
/*Comment sait-on sur quelle case de la carte on se trouve? Il suffit de prendre les coordonn�es de la souris
(event.button.x par exemple), et de diviser cette valeur par la taille d'un bloc (TAILLE_BLOC). C'est une division d'un
nombre entiers. Comme en C une division d'un nombre entiers donne un nombre entier, on est s�r d'avoir une valeur qui
corresponde � une de cases.
Par exemple, si je suis au 75eme pixel sur la carte (sur l'axe des abscisses x), je divise ce nombre par TAILLE_BLOC qui vaut
ici 34. 75 / 34 = 2, le reste est ignor�.
Autre exemple, si je suis au 10eme pixel (c'est � dire tr�s proche du bord), ca va donner le calcul suivant: 10 / 34 = 0
On est donc � la case n 0.
Autre chose importante: on met un bool�en clicGaucheEnCours (ou clicDroit selon le cas) � 1. Cela nous permettra de savoir lors
d'un �v�nement MOUSEMOTION si un bouton de la souris est enfonc� pendant le d�placement*/

/*SDL_MOUSEMOTION: c'est l� que les bool�ens prennent leurs importances, On v�rifie quand on bouge la souris si un clic est
en cours. Si tel est le cas, on place sur la carte un objet (ou du vide si c'est un clic droit), cela permet de placer
d'affil�e plusieurs objets du m�me type sans avoir � cliquer plusieurs fois. On a juste � d�placer la souris en maintenant
son bouton enfonc�!
R�sum� de la technique: 1.Lors d'un MOUSEBUTTONDOWN: on met un bool�en � 1
2.Lors d'un MOUSEMOTION: on teste si le bool�en clicEnCours vaut vrai, s'il vaut vrai, on sait qu'on est en train de faire
une sorte de glisser-d�placer avec la souris
3.Lors d'un MOUSEBUTTONUP: on remet le bool�n clicEnCours � 0, car le clic est termin� (rel�chement du bouton de la souris)*/

//Blit time
//Effacement de l'�cran
SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
//PLacement des objets � l'�cran
for(i = 0; i < NB_BLOCS_LARGEUR; i++){

        for(j = 0; j < NB_BLOCS_HAUTEUR; j++){
            position.x = i * TAILLE_BLOC;
            position.y = j * TAILLE_BLOC;

            switch(carte[i][j]){
            case MUR:
                SDL_BlitSurface(mur,NULL,ecran,&position);
                break;
            case CAISSE:
                SDL_BlitSurface(caisse,NULL,ecran,&position);
                break;
            case OBJECTIF:
                SDL_BlitSurface(objectif,NULL,ecran,&position);
                break;
            case MARIO:
                SDL_BlitSurface(mario,NULL,ecran,&position);
                break;
            }
        }
        //Mise � jour de l'�cran
        SDL_Flip(ecran);
    }

    //Lib�ration des surfaces charg�es
    SDL_FreeSurface(mur);
    SDL_FreeSurface(caisse);
    SDL_FreeSurface(objectif);
    SDL_FreeSurface(mario);

}


