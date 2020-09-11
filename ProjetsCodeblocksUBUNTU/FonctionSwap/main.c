#include <stdio.h>
#include <stdlib.h>

 void swap(int *pointeursura, int *pointeursurb);

int main(int argc, char *argv[])
{
int a = 9, b = 5;


printf("%d %d\n", a,b);

swap(&a, &b);

printf("%d %d", a,b);

return 0;
}

 void swap(int *pointeursura, int *pointeursurb)
{
 int c;
c = *pointeursurb;
*pointeursura = *pointeursurb;
 *pointeursura = c;

}
