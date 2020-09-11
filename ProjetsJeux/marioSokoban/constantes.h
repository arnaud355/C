//Rôle: On définit des constantes pour tout le programme (taille de la fenetre...)
#ifndef DEF_CONSTANTES
#define DEF_CONSTANTES

    #define TAILLE_BLOC 34 //Taille d'un bloc(carré) en pixels, les sprites du projet sont des carre des 34 * 34 pixels
    #define NB_BLOCS_LARGEUR 12
    #define NB_BLOCS_HAUTEUR 12
    #define LARGEUR_FENETRE TAILLE_BLOC * NB_BLOCS_LARGEUR
    #define HAUTEUR_FENETRE TAILLE_BLOC * NB_BLOCS_HAUTEUR

    enum{HAUT,BAS,GAUCHE,DROITE}; /*On met des constantes à des valeurs différentes, c'est l'ordinateur qui s'en charge
    (et non le compilateur, comme pour define) de les mettre de 0 à n, ça nous importe pas de les mettre à une valeur précise*/
    enum{VIDE,MUR,CAISSE,OBJECTIF,MARIO,CAISSE_OK};

#endif
