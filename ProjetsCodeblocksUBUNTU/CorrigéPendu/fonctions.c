
char lireCaractere()
{
char caractere = 0;
caractere = getchar();    /*L'utilisateur entre une lettre, cette fonction getchar() est une fonction de stdio
                            elle revient au même que d'écrire: scanf("%c", &lettreEntre), sauf que la diff
                            est que l'on pourras ne pas prendre en compte la touche Entree, voir ci-dessous. */

caractere = toupper(caractere);/*La fonction toupper va mettre en majuscule le caractère, si ce n'est déjà fait.*/

while(getchar() != '\n');   /*Contrairement à la fonction scanf qui enregistre la touche Entree, ce qui fausse
                            le programme si l'on veut faire appelle à la fonction scanf dans le même code source
                            l'on peut avec cette fonction getchar faire une boucle jusqu'à ce que l'utilisateur
                            appuie sur Entree. Si par mégarde ou pour faire chier le monde l'utilsateur a
                            entrée un mot et non une lettre, c'est la première lettre qui seras pris en compte
                            Les autres lettres seront vidés de la mémoire, on dit qu'on vide le buffer.*/
}

int gagne(int lettreTrouvee[])
{
    int i = 0;
    int joueurGagne = 1;
    for(i = 0; i < 6; i++)
    {
        if(lettreTrouvee[i] == 0)
        {
            joueurGagne = 0;
        }
    }
    return joueurGagne;

}

int rechercheLettre(char lettre, char motSecret[], int lettreTrouvee[])
{
    int i = 0;
    int bonneLettre = 0;

    /*On parcourt motSecret pour vérifier si la lettre proposée y est*/
    for(i = 0; motSecret[i] != '\0'; i++)
    {
        if(lettre == motSecret[i])  /*Si la lettre y est*/
        {
            bonneLettre = 1; /*On mémorise que c'était une bonne lettre*/
            lettreTrouvee[i] = 1; /*On met à 1 la case du tableau de booléens correspondant à la lettre actuelle*/
        }
    }
    return bonneLettre;

}
