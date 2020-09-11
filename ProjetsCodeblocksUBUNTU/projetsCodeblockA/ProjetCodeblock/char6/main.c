#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* strstr(const char* chaine, const char* chainearechercher);

int main(int argc, char *argv[])
{
    char *suiteChaine;

    suiteChaine = strstr("Texte de test","test");
    if(suiteChaine != NULL)
    {
        printf("%s", suiteChaine);
    }
    return 0;
}
