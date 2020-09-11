//Rôle: fonction du jeu, chargement de sprites, décors
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
/*à quoi sert marioActuel? c'est un pointeur qui servira à pointer sur la surface correspondant au mario orienté dans la
direction actuelle, pourquoi un pointeur? car en y mettant une nouvelle image de mario (nouvelle direction) on récupère
aussi les nouvelles coordonnées x et y (stocké dans la strucuture SDL_Surface), il faut donc un pointeur pour prendre en
charge et renvoyer les valeurs, puisque qu'i y en a au moins deux.
la variable position servira à définir la position des éléments à blitter, positionJoueur indiquera
à quelle case se trouve le joueur, et enfin la variable event traitera les événements */

int continuer = 1, objectifsRestants = 0,i = 0, j = 0;
int carte[NB_BLOCS_LARGEUR][NB_BLOCS_HAUTEUR] = {0};
/*continuer et objectifsRestants sont des booléens, i et j sont des variables qui vont me permettre de me balader dans
le tableau. Selon la valeur de la case(qui est un nombre entier),on sait si la case contient un mur, une caisse,
un objectif,etc). C'est à ça que va nous servir notre énumération: enum{VIDE,MUR,CAISSE,OBJECTIF,MARIO,CAISSE_OK};
Si la case vaut VIDE(0) on sait que la partie de l'écran devra rester blanche, si elle vaut MUR(1), on sait qu'il faudra
blitter une image de mur*/

//Initialisation
//Chargement des sprites(décors,personnage...)
mur = IMG_Load("mur.jpg");
caisse = IMG_Load("caisse.jpg");
caisseOK = IMG_Load("caisse_ok.jpg");
objectif = IMG_Load("objectif.png");
mario[BAS] = IMG_Load("mario_bas.gif");//Le fait d'utiliser les constantes rend le tableau mario plus clair, marche aussi:mario[0]
mario[GAUCHE] = IMG_Load("mario_gauche.gif");
mario[HAUT] = IMG_Load("mario_haut.gif");
mario[DROITE] = IMG_Load("mario_droite.gif");

marioActuel = mario[BAS];//On initialise mario pour qu'il ait une direction de départ

//Chargement de niveau (chargement et sauvegarde par des fonctions situées dans fichier.c
    if(!chargerNiveau(carte)){
                        fprintf(stderr,"Erreur d'initialisation de la SDL: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);//On arrête le jeu si on n'as pas pu charger le niveau
    }


/*cette variable de type SDL_Rect est un peu particulière, on ne s'en sert pas pour stocker des coordonnées en pixels,
mais pour stocker des coordonnées en cases sur la carte, d'où le ==.*/
//On parcourt le tableau avec une double boucle, i pour parcourir verticalement et j pour parcourir horizontalement
//Recherche de la position de mario au départ
    for(i = 0; i < NB_BLOCS_LARGEUR; i++){
    for(j = 0; j < NB_BLOCS_HAUTEUR; j++){
        if(carte[i][j] == MARIO){//à chaque case on teste si elle contient mario  et on stocke les coordonnées actuelles de i,j
            positionJoueur.x = i;
            positionJoueur.y = j;
            carte[i][j] = VIDE;//On vide ensuite la case pour qu'elle soit considéreé comme vide par la suite
            }
        }
    }
//Activation de la répétition des touches
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

/*On dirige mario dans une des direction au clavier, et on y affecte l'image correspondant à la direction dans marioActuel,
ensuite on envoie à la fonction déplacerJoueur trois paramètres: -la carte, pour qu'elle puisse la lire ou la modifier si on
déplace une caisse (il faudra gérer la colission , et autoriser telle ou telle déplacement).
-La position du joueur: là aussiil faudra lire et éventuellement modifier la position du joueur.
-la direction dans laquelle on demande à aller: on utilise là encore les constantes HAUT,BAS,GAUCHE,DROITE.*/

/*Notre switch est terminé: à ce stade du programme, la carte et le joueur ont probablement changé. Quoi qu'il en soit c'est
l'heure du blit!*/
//Effacement de l'écran
/*Et maintenant on parcourt tout le tableau à deux dimensions carte pour savoir quel éléments blitter à quel endroit,
on effectue une double boucle, comme plus tôt, pour parcourir les 144 cases du tableau.*/

//Placement des objets à l'écran
objectifsRestants = 0;
 // Effacement de l'écran
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
    //Si on n'a trouvé aucun objectif sur la carte, c'est qu'on a gagné
        if(!objectifsRestants){
        continuer = 0;
        }
        //On place le joueur à la bonne position
        position.x = positionJoueur.x * TAILLE_BLOC;
        position.y = positionJoueur.y * TAILLE_BLOC;
        SDL_BlitSurface(marioActuel,NULL,ecran,&position);
        /*On calcule sa position (en pixels cette fois) en faisant une simple multiplication entre positionJoueur et TAILLE_BLOC.
        On blitte ensuite le joueur à la position indiquée*/
        SDL_Flip(ecran);
    }
/*Après la boucle principale, on doit faire quelques FreeSurface pour libérer la mémoire des sprites qu'on a chargés. On
désactive aussi la répétition des touches en envoyant les valeurs 0 à la fonction SDL_EnableKeyRepeat:*/
SDL_EnableKeyRepeat(0,0);

    //Libération des surfaces chargées
    SDL_FreeSurface(mur);
    SDL_FreeSurface(caisse);
    SDL_FreeSurface(caisseOK);
    SDL_FreeSurface(objectif);
    for(i = 0; i < 4; i++){
        SDL_FreeSurface(mario[i]);
    }

}
/*La fonction deplacerJoueur se trouve elle aussi dans jeu.c. elle vérifie si on a le droit de déplacer le jueur dans la
direction demandée. Elle met à jour la position du joueur(positionJoueur) et aussi la carte si une caisse a été déplacée.
voici le prototype de la fonction:
void deplacerJoueur(int carte[][NB_BLOCS_HAUTEUR], SDL_Rect *pos,int direction);
dans cette fonction j'envoie le tableau carte et je précise la taille de la deuxième dimension , pourquoi cela?
le C ne devine pas qu'il s'agit d'un tableau à deux dimensions et il faut lui donner au moins la taille de la seconde
dimension pour que ça fonctionne. On doit indiquer la taille de la seonde dimension dans le protype, c'est obligatoire.*/
void deplacerJoueur(int carte[][NB_BLOCS_HAUTEUR], SDL_Rect *pos,int direction){
    switch(direction){
    case HAUT:
        if(pos->y - 1 < 0)//Si le joueur dépasse l'écran on arrête
            break;
        if(carte[pos->x][pos->y - 1] == MUR)//S'il y a un mur au-dessus du joueur, on arrête
        break;
    //Si on veut pousser une caisse, il faut vérifier qu'il n'y a pas de mur derrière (ou une autre caisse, ou limite du monde)
    if((carte[pos->x][pos->y - 1] == CAISSE || carte[pos->x][pos->y - 1] == CAISSE_OK) && (pos->y - 2 < 0 || carte[pos->x][pos->y - 2] == MUR || carte[pos->x][pos->y - 2] == CAISSE || carte[pos->x][pos->y - 2] == CAISSE_OK))
        break;
    /*Ce gros test peut se traduire: SI au-dessus du joueur il y a une caisse (ou une caisse_ok, c'est à dire une caisse bien
    placée) ET SI au dessus de cette caisse il y a soit le vide(on déborde du niveau car on est tout en haut), soit une autre
    caisse, soit une caisse_OK: ALORS on ne peut pas se déplacer: break. */

    //Si on arrive là, cest qu'on peut déplacer le joueur!
    //On vérifie d'abord s'il y a une caisse à déplacer
    deplacerCaisse(&carte[pos->x][pos->y - 1],&carte[pos->x][pos->y - 2]);

    pos->y--; //On peuut enfin faire monter le joueur
    break;

    case DROITE:
        if(pos->x + 1 >= NB_BLOCS_LARGEUR)//Si le joueur dépasse l'écran on arrête
            break;
        if(carte[pos->x + 1][pos->y] == MUR)//S'il y a un mur à droite du joueur, on arrête
        break;
    //Si on veut pousser une caisse, il faut vérifier qu'il n'y a pas de mur derrière (ou une autre caisse, ou limite du monde)
    if((carte[pos->x + 1][pos->y] == CAISSE || carte[pos->x + 1][pos->y] == CAISSE_OK) && (pos->x + 2 < NB_BLOCS_LARGEUR || carte[pos->x + 2][pos->y] == MUR || carte[pos->x + 2][pos->y] == CAISSE || carte[pos->x + 2][pos->y] == CAISSE_OK))
        break;
    /*Ce gros test peut se traduire: SI au-dessus du joueur il y a une caisse (ou une caisse_ok, c'est à dire une caisse bien
    placée) ET SI au dessus de cette caisse il y a soit le vide(on déborde du niveau car on est tout en haut), soit une autre
    caisse, soit une caisse_OK: ALORS on ne peut pas se déplacer: break. */

    //Si on arrive là, cest qu'on peut déplacer le joueur!
    //On vérifie d'abord s'il y a une caisse à déplacer
    deplacerCaisse(&carte[pos->x + 1][pos->y],&carte[pos->x + 2][pos->y]);

    pos->x++; //On peuut enfin déplacer le joueur vers la droite
    break;

    case GAUCHE:
        if(pos->x - 1 < 0)//Si le joueur dépasse l'écran on arrête
            break;
        if(carte[pos->x - 1][pos->y] == MUR)//S'il y a un mur à droite du joueur, on arrête
        break;
    //Si on veut pousser une caisse, il faut vérifier qu'il n'y a pas de mur derrière (ou une autre caisse, ou limite du monde)
    if((carte[pos->x - 1][pos->y] == CAISSE || carte[pos->x - 1][pos->y] == CAISSE_OK) && (pos->x - 2 < NB_BLOCS_LARGEUR || carte[pos->x - 2][pos->y] == MUR || carte[pos->x - 2][pos->y] == CAISSE || carte[pos->x - 2][pos->y] == CAISSE_OK))
        break;
    /*Ce gros test peut se traduire: SI au-dessus du joueur il y a une caisse (ou une caisse_ok, c'est à dire une caisse bien
    placée) ET SI au dessus de cette caisse il y a soit le vide(on déborde du niveau car on est tout en haut), soit une autre
    caisse, soit une caisse_OK: ALORS on ne peut pas se déplacer: break. */

    //Si on arrive là, cest qu'on peut déplacer le joueur!
    //On vérifie d'abord s'il y a une caisse à déplacer
    deplacerCaisse(&carte[pos->x - 1][pos->y],&carte[pos->x - 2][pos->y]);

    pos->x--; //On peuut enfin déplacer le joueur vers la gauche
    break;

     case BAS:
        if(pos->y + 1 >= NB_BLOCS_HAUTEUR)//Si le joueur dépasse l'écran on arrête
            break;
        if(carte[pos->x][pos->y + 1] == MUR)//S'il y a un mur au-dessus du joueur, on arrête
        break;
    //Si on veut pousser une caisse, il faut vérifier qu'il n'y a pas de mur derrière (ou une autre caisse, ou limite du monde)
    if((carte[pos->x][pos->y + 1] == CAISSE || carte[pos->x][pos->y + 1] == CAISSE_OK) && (pos->y + 2 > NB_BLOCS_HAUTEUR || carte[pos->x][pos->y + 2] == MUR || carte[pos->x][pos->y + 2] == CAISSE || carte[pos->x][pos->y + 2] == CAISSE_OK))
        break;
    /*Ce gros test peut se traduire: SI au-dessus du joueur il y a une caisse (ou une caisse_ok, c'est à dire une caisse bien
    placée) ET SI au dessus de cette caisse il y a soit le vide(on déborde du niveau car on est tout en haut), soit une autre
    caisse, soit une caisse_OK: ALORS on ne peut pas se déplacer: break. */

    //Si on arrive là, cest qu'on peut déplacer le joueur!
    //On vérifie d'abord s'il y a une caisse à déplacer
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
