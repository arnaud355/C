typedef struct Personne Personne;   /*j'ai créee un alias en commençant par typedef struct Personne avec
                                    un alias Personne, ça éviteras d'écrire struct Personne à chaque fois.
                                    strutc veut dire structure c'est un assemblage de plusieurs variables.*/

struct Personne
{
    char prenom[50];
    char nom[50];
    char pseudo[50];

};



