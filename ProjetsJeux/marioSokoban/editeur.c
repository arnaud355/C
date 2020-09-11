//Rôle: fonction du jeu, chargement de sprites, décors
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
/*Les booleens clicGaucheEnCours et clicDroitEnCours permettent de mémoriser si un clic est en cours (bouton souris enfoncé)
cela nous permettra de poser des objets à l'écran en laissant le bouton gauche de la souris enfoncé (sinon on est obligé
de cliquer frénétiquement avec la souris pour placer plusieurs fois le même objet à différents endroits*/

//Chargement des objets et du niveau
mur = IMG_Load("mur.jpg");
caisse = IMG_Load("caisse.jpg");
objectif = IMG_Load("objectif.png");
mario = IMG_Load("mario_bas.gif");
/*Je ne charge qu'un seul Mario, en effet on ne va pas diriger Mario au clavier là, on a juste besoin d'un sprite représentant
la position de Mario au départ.
La variable objetActuel retient lo'bjet sélectionné par l'utilisateur, par défaut c'est un MUR, mais cela pourra être changé
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
                //On met l'objet actuellement choisi (mur,caisse...) à l'endroit du clic
                carte[event.button.x / TAILLE_BLOC][event.button.y / TAILLE_BLOC] = objetActuel;
                clicGaucheEnCours = 1; //On retient qu'un bouton est enfoncé
            }
            else if(event.button.button == SDL_BUTTON_RIGHT){//clic droit pour effacer
                 carte[event.button.x / TAILLE_BLOC][event.button.y / TAILLE_BLOC] = VIDE;
                clicDroitEnCours = 1;
            }
            break;
        case SDL_MOUSEBUTTONUP: //On désactive le booléen qui disait qu'un bouton était enfoncé
            if(event.button.button == SDL_BUTTON_LEFT)
                clicGaucheEnCours = 0;
            else if(event.button.button == SDL_BUTTON_RIGHT)
                clicDroitEnCours = 0;
            break;
        /*L'évenement MOUSEBUTTONUP sert simplement à remettre le booléen à 0, on sait que le clic est terminé et donc qu'il
        ny'a plus de clic en cours*/
        case SDL_MOUSEMOTION:
            if(clicGaucheEnCours){//Si on déplace la souris et que le bouton gauche de la souris est enfoncé
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
/*Comment sait-on sur quelle case de la carte on se trouve? Il suffit de prendre les coordonnées de la souris
(event.button.x par exemple), et de diviser cette valeur par la taille d'un bloc (TAILLE_BLOC). C'est une division d'un
nombre entiers. Comme en C une division d'un nombre entiers donne un nombre entier, on est sûr d'avoir une valeur qui
corresponde à une de cases.
Par exemple, si je suis au 75eme pixel sur la carte (sur l'axe des abscisses x), je divise ce nombre par TAILLE_BLOC qui vaut
ici 34. 75 / 34 = 2, le reste est ignoré.
Autre exemple, si je suis au 10eme pixel (c'est à dire très proche du bord), ca va donner le calcul suivant: 10 / 34 = 0
On est donc à la case n 0.
Autre chose importante: on met un booléen clicGaucheEnCours (ou clicDroit selon le cas) à 1. Cela nous permettra de savoir lors
d'un évènement MOUSEMOTION si un bouton de la souris est enfoncé pendant le déplacement*/

/*SDL_MOUSEMOTION: c'est là que les booléens prennent leurs importances, On vérifie quand on bouge la souris si un clic est
en cours. Si tel est le cas, on place sur la carte un objet (ou du vide si c'est un clic droit), cela permet de placer
d'affilée plusieurs objets du même type sans avoir à cliquer plusieurs fois. On a juste à déplacer la souris en maintenant
son bouton enfoncé!
Résumé de la technique: 1.Lors d'un MOUSEBUTTONDOWN: on met un booléen à 1
2.Lors d'un MOUSEMOTION: on teste si le booléen clicEnCours vaut vrai, s'il vaut vrai, on sait qu'on est en train de faire
une sorte de glisser-déplacer avec la souris
3.Lors d'un MOUSEBUTTONUP: on remet le boolén clicEnCours à 0, car le clic est terminé (relâchement du bouton de la souris)*/

//Blit time
//Effacement de l'écran
SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
//PLacement des objets à l'écran
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
        //Mise à jour de l'écran
        SDL_Flip(ecran);
    }

    //Libération des surfaces chargées
    SDL_FreeSurface(mur);
    SDL_FreeSurface(caisse);
    SDL_FreeSurface(objectif);
    SDL_FreeSurface(mario);

}


