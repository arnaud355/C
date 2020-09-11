#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
  int x = 0, y;

  printf("y = 2x - 1\n\n");
  printf("Entrez un nombre qui viendra prendre la valeur de x!\n\n");
  scanf("%d",&x);
  y = (x * 2 - 1);
  printf("pour x = %d y =%d",x,y);
    return 0;
}
