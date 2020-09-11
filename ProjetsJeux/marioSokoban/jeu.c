//R�le: fonction du jeu, chargement de sprites, d�cors
#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include "constantes.h"
#include "jeu.h"


void jouer(SDL_Surface *ecran){
SDL_Surface *mario[4] = {NULL};//tableau de 4 cases, qui stockera Mario dans chacune des 4 directions
SDL_Surface *mur = NULL, *caisse = NULL, *caisseOK = NULL, *objectif = NULL,*marioActuel = NULL;
SDL_Rect position, positionJoueur;
SDL_Event event;
/*� quoi sert marioActuel? c'est un pointeur qui servira � pointer sur la surface correspondant au mario orient� dans la
direction actuelle, pourquoi un pointeur? car en y mettant une nouvelle image de mario (nouvelle direction) on r�cup�re
aussi les nouvelles coordonn�es x et y (stock� dans la strucuture SDL_Surface), il faut donc un pointeur pour prendre en
charge et renvoyer les valeurs, puisque qu'i y en a au moins deux.
la variable position servira � d�finir la position des �l�ments � blitter, positionJoueur indiquera
� quelle case se trouve le joueur, et enfin la variable event traitera les �v�nements */

int continuer = 1, objectifsRestants = 0,i = 0, j = 0;
int carte[NB_BLOCS_LARGEUR][NB_BLOCS_HAUTEUR] = {0};
/*continuer et objectifsRestants sont des bool�ens, i et j sont des variables qui vont me permettre de me balader dans
le tableau. Selon la valeur de la case(qui est un nombre entier),on sait si la case contient un mur, une caisse,
un objectif,etc). C'est � �a que va nous servir notre �num�ration: enum{VIDE,MUR,CAISSE,OBJECTIF,MARIO,CAISSE_OK};
Si la case vaut VIDE(0) on sait que la partie de l'�cran devra rester blanche, si elle vaut MUR(1), on sait qu'il faudra
blitter une image de mur*/

//Initialisation
//Chargement des sprites(d�cors,personnage...)
mur = IMG_Load("mur.jpg");
caisse = IMG_Load("caisse.jpg");
caisseOK = IMG_Load("caisse_ok.jpg");
objectif = IMG_Load("objectif.png");
mario[BAS] = IMG_Load("mario_bas.gif");//Le fait d'utiliser les constantes rend le tableau mario plus clair, marche aussi:mario[0]
mario[GAUCHE] = IMG_Load("mario_gauche.gif");
mario[HAUT] = IMG_Load("mario_haut.gif");
mario[DROITE] = IMG_Load("mario_droite.gif");

marioActuel = mario[BAS];//On initialise mario pour qu'il ait une direction de d�part

//Chargement de niveau (chargement et sauvegarde par des fonctions situ�es dans fichier.c
    if(!chargerNiveau(carte)){
                        fprintf(stderr,"Erreur d'initialisation de la SDL: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);//On arr�te le jeu si on n'as pas pu charger le niveau
    }


/*cette variable de type SDL_Rect est un peu particuli�re, on ne s'en sert pas pour stocker des coordonn�es en pixels,
mais pour stocker des coordonn�es en cases sur la carte, d'o� le ==.*/
//On parcourt le tableau avec une double boucle, i pour parcourir verticalement et j pour parcourir horizontalement
//Recherche de la position de mario au d�part
    for(i = 0; i < NB_BLOCS_LARGEUR; i++){
    for(j = 0; j < NB_BLOCS_HAUTEUR; j++){
        if(carte[i][j] == MARIO){//� chaque case on teste si elle contient mario  et on stocke les coordonn�es actuelles de i,j
            positionJoueur.x = i;
            positionJoueur.y = j;
            carte[i][j] = VIDE;//On vide ensuite la case pour qu'elle soit consid�re� comme vide par la suite
            }
        }
    }
//Activation de la r�p�tition des touches
SDL_EnableKeyRepeat(100,100);

//La boucle principale: les initialisations sont faites, on peut s'occuper de la boucle principale.
  while(continuer){
    switch(event.type){
    case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym){
            case SDLK_ESCAPE:
                continuer = 0;
            case SDLK_UP:
                marioActuel = mario[HAUT];
                deplacerJoueur(carte, &positionJoueur,HAUT);
                break;
            case SDLK_DOWN:
                 marioActuel = mario[BAS];
                deplacerJoueur(carte, &positionJoueur,HAUT);
                break;
            case SDLK_RIGHT:
                 marioActuel = mario[DROITE];
                deplacerJoueur(carte, &positionJoueur,HAUT);
                break;
            case SDLK_LEFT:
                 marioActuel = mario[GAUCHE];
                deplacerJoueur(carte, &positionJoueur,HAUT);
                break;
            }
            break;
    }

/*On dirige mario dans une des direction au clavier, et on y affecte l'image correspondant � la direction dans marioActuel,
ensuite on envoie � la fonction d�placerJoueur trois param�tres: -la carte, pour qu'elle puisse la lire ou la modifier si on
d�place une caisse (il faudra g�rer la colission , et autoriser telle ou telle d�placement).
-La position du joueur: l� aussiil faudra lire et �ventuellement modifier la position du joueur.
-la direction dans laquelle on demande � aller: on utilise l� encore les constantes HAUT,BAS,GAUCHE,DROITE.*/

/*Notre switch est termin�: � ce stade du programme, la carte et le joueur ont probablement chang�. Quoi qu'il en soit c'est
l'heure du blit!*/
//Effacement de l'�cran
/*Et maintenant on parcourt tout le tableau � deux dimensions carte pour savoir quel �l�ments blitter � quel endroit,
on effectue une double boucle, comme plus t�t, pour parcourir les 144 cases du tableau.*/

//Placement des objets � l'�cran
objectifsRestants = 0;
 // Effacement de l'�cran
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

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
            case CAISSE_OK:
                SDL_BlitSurface(caisseOK,NULL,ecran,&position);
                break;
            case OBJECTIF:
                SDL_BlitSurface(objectif,NULL,ecran,&position);
                objectifsRestants = 1;
                break;
            }
        }
    }
    //Si on n'a trouv� aucun objectif sur la carte, c'est qu'on a gagn�
        if(!objectifsRestants){
        continuer = 0;
        }
        //On place le joueur � la bonne position
        position.x = positionJoueur.x * TAILLE_BLOC;
        position.y = positionJoueur.y * TAILLE_BLOC;
        SDL_BlitSurface(marioActuel,NULL,ecran,&position);
        /*On calcule sa position (en pixels cette fois) en faisant une simple multiplication entre positionJoueur et TAILLE_BLOC.
        On blitte ensuite le joueur � la position indiqu�e*/
        SDL_Flip(ecran);
    }
/*Apr�s la boucle principale, on doit faire quelques FreeSurface pour lib�rer la m�moire des sprites qu'on a charg�s. On
d�sactive aussi la r�p�tition des touches en envoyant les valeurs 0 � la fonction SDL_EnableKeyRepeat:*/
SDL_EnableKeyRepeat(0,0);

    //Lib�ration des surfaces charg�es
    SDL_FreeSurface(mur);
    SDL_FreeSurface(caisse);
    SDL_FreeSurface(caisseOK);
    SDL_FreeSurface(objectif);
    for(i = 0; i < 4; i++){
        SDL_FreeSurface(mario[i]);
    }

}
/*La fonction deplacerJoueur se trouve elle aussi dans jeu.c. elle v�rifie si on a le droit de d�placer le jueur dans la
direction demand�e. Elle met � jour la position du joueur(positionJoueur) et aussi la carte si une caisse a �t� d�plac�e.
voici le prototype de la fonction:
void deplacerJoueur(int carte[][NB_BLOCS_HAUTEUR], SDL_Rect *pos,int direction);
dans cette fonction j'envoie le tableau carte et je pr�cise la taille de la deuxi�me dimension , pourquoi cela?
le C ne devine pas qu'il s'agit d'un tableau � deux dimensions et il faut lui donner au moins la taille de la seconde
dimension pour que �a fonctionne. On doit indiquer la taille de la seonde dimension dans le protype, c'est obligatoire.*/
void deplacerJoueur(int carte[][NB_BLOCS_HAUTEUR], SDL_Rect *pos,int direction){
    switch(direction){
    case HAUT:
        if(pos->y - 1 < 0)//Si le joueur d�passe l'�cran on arr�te
            break;
        if(carte[pos->x][pos->y - 1] == MUR)//S'il y a un mur au-dessus du joueur, on arr�te
        break;
    //Si on veut pousser une caisse, il faut v�rifier qu'il n'y a pas de mur derri�re (ou une autre caisse, ou limite du monde)
    if((carte[pos->x][pos->y - 1] == CAISSE || carte[pos->x][pos->y - 1] == CAISSE_OK) && (pos->y - 2 < 0 || carte[pos->x][pos->y - 2] == MUR || carte[pos->x][pos->y - 2] == CAISSE || carte[pos->x][pos->y - 2] == CAISSE_OK))
        break;
    /*Ce gros test peut se traduire: SI au-dessus du joueur il y a une caisse (ou une caisse_ok, c'est � dire une caisse bien
    plac�e) ET SI au dessus de cette caisse il y a soit le vide(on d�borde du niveau car on est tout en haut), soit une autre
    caisse, soit une caisse_OK: ALORS on ne peut pas se d�placer: break. */

    //Si on arrive l�, cest qu'on peut d�placer le joueur!
    //On v�rifie d'abord s'il y a une caisse � d�placer
    deplacerCaisse(&carte[pos->x][pos->y - 1],&carte[pos->x][pos->y - 2]);

    pos->y--; //On peuut enfin faire monter le joueur
    break;

    case DROITE:
        if(pos->x + 1 >= NB_BLOCS_LARGEUR)//Si le joueur d�passe l'�cran on arr�te
            break;
        if(carte[pos->x + 1][pos->y] == MUR)//S'il y a un mur � droite du joueur, on arr�te
        break;
    //Si on veut pousser une caisse, il faut v�rifier qu'il n'y a pas de mur derri�re (ou une autre caisse, ou limite du monde)
    if((carte[pos->x + 1][pos->y] == CAISSE || carte[pos->x + 1][pos->y] == CAISSE_OK) && (pos->x + 2 < NB_BLOCS_LARGEUR || carte[pos->x + 2][pos->y] == MUR || carte[pos->x + 2][pos->y] == CAISSE || carte[pos->x + 2][pos->y] == CAISSE_OK))
        break;
    /*Ce gros test peut se traduire: SI au-dessus du joueur il y a une caisse (ou une caisse_ok, c'est � dire une caisse bien
    plac�e) ET SI au dessus de cette caisse il y a soit le vide(on d�borde du niveau car on est tout en haut), soit une autre
    caisse, soit une caisse_OK: ALORS on ne peut pas se d�placer: break. */

    //Si on arrive l�, cest qu'on peut d�placer le joueur!
    //On v�rifie d'abord s'il y a une caisse � d�placer
    deplacerCaisse(&carte[pos->x + 1][pos->y],&carte[pos->x + 2][pos->y]);

    pos->x++; //On peuut enfin d�placer le joueur vers la droite
    break;

    case GAUCHE:
        if(pos->x - 1 < 0)//Si le joueur d�passe l'�cran on arr�te
            break;
        if(carte[pos->x - 1][pos->y] == MUR)//S'il y a un mur � droite du joueur, on arr�te
        break;
    //Si on veut pousser une caisse, il faut v�rifier qu'il n'y a pas de mur derri�re (ou une autre caisse, ou limite du monde)
    if((carte[pos->x - 1][pos->y] == CAISSE || carte[pos->x - 1][pos->y] == CAISSE_OK) && (pos->x - 2 < NB_BLOCS_LARGEUR || carte[pos->x - 2][pos->y] == MUR || carte[pos->x - 2][pos->y] == CAISSE || carte[pos->x - 2][pos->y] == CAISSE_OK))
        break;
    /*Ce gros test peut se traduire: SI au-dessus du joueur il y a une caisse (ou une caisse_ok, c'est � dire une caisse bien
    plac�e) ET SI au dessus de cette caisse il y a soit le vide(on d�borde du niveau car on est tout en haut), soit une autre
    caisse, soit une caisse_OK: ALORS on ne peut pas se d�placer: break. */

    //Si on arrive l�, cest qu'on peut d�placer le joueur!
    //On v�rifie d'abord s'il y a une caisse � d�placer
    deplacerCaisse(&carte[pos->x - 1][pos->y],&carte[pos->x - 2][pos->y]);

    pos->x--; //On peuut enfin d�placer le joueur vers la gauche
    break;

     case BAS:
        if(pos->y + 1 >= NB_BLOCS_HAUTEUR)//Si le joueur d�passe l'�cran on arr�te
            break;
        if(carte[pos->x][pos->y + 1] == MUR)//S'il y a un mur au-dessus du joueur, on arr�te
        break;
    //Si on veut pousser une caisse, il faut v�rifier qu'il n'y a pas de mur derri�re (ou une autre caisse, ou limite du monde)
    if((carte[pos->x][pos->y + 1] == CAISSE || carte[pos->x][pos->y + 1] == CAISSE_OK) && (pos->y + 2 > NB_BLOCS_HAUTEUR || carte[pos->x][pos->y + 2] == MUR || carte[pos->x][pos->y + 2] == CAISSE || carte[pos->x][pos->y + 2] == CAISSE_OK))
        break;
    /*Ce gros test peut se traduire: SI au-dessus du joueur il y a une caisse (ou une caisse_ok, c'est � dire une caisse bien
    plac�e) ET SI au dessus de cette caisse il y a soit le vide(on d�borde du niveau car on est tout en haut), soit une autre
    caisse, soit une caisse_OK: ALORS on ne peut pas se d�placer: break. */

    //Si on arrive l�, cest qu'on peut d�placer le joueur!
    //On v�rifie d'abord s'il y a une caisse � d�placer
    deplacerCaisse(&carte[pos->x][pos->y + 1],&carte[pos->x][pos->y + 2]);

    pos->y++; //On peuut enfin faire descendre le joueur
    break;

    }
}

void deplacerCaisse(int *premiereCase, int *secondeCase){
   if(*premiereCase == CAISSE || *premiereCase == CAISSE_OK){
          if(*secondeCase == OBJECTIF)
            *secondeCase = CAISSE_OK;
            else
                *secondeCase = CAISSE;

        if(*premiereCase == CAISSE_OK)
            *premiereCase = OBJECTIF;
        else
            *premiereCase = VIDE;
   }

}
