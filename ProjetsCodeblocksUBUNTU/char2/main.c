#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char prenom[80]; /* J'ai déclaré une variable prenom, je vais demander à un utilisateur de rentrer son
                        prenom. Mais je ne connais pas sa taille (son nombre de lettres). Je prend donc une
                        grande taille pour être sûr de ne pas être trop juste.*/

    printf("Comment t appelles-tu petit zero?\n");
    scanf("%s", prenom);                             /* Il n'y a pas de & pour ce scanf, car c'est un tableau
                                                        de type string (%s).*/
    printf("Salut %s, enchante", prenom);
    return 0;
}
