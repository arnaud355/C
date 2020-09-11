#include <stdio.h>
#include <stdlib.h>

double conversion(double Euros)
{

   return 6.556 * Euros;

}


int main(int argc, char *argv[])
{

   printf("10 euros = %fF\n", conversion(10));
   printf("50 euros = %fF\n", conversion(50));
    return 0;
}
