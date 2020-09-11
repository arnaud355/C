int combien(const char* mot);

int combien(const char* mot)
{

int compteurdea = 0;
int compteurnumdea = 0;

do
{

if(compteurdea == 97)
{
compteurnumdea++;
}
}while(compteurdea != '\0');

return compteurnumdea;
}
