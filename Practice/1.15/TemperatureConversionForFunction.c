#include <stdio.h>
#define UPPER 300
#define STEP 20
#define LOWER 0
/* print Fahrenhiet-Celsius table
 * for fahr = 0, 20, ..., 300 */
int fahrconversion(int n);

int main (void)
{
	int fahr;
   for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
	  printf("%5d %5d\n", fahr, fahrconversion(fahr)); 
   return 0;
}

int fahrconversion(int fahr)
{
	int celsius;
	celsius = 5 * (fahr - 32) / 9;
	return celsius;
}
