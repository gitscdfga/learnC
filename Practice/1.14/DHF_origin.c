#include <stdio.h>
#define MAXCHAR 123
#define MAXHIST 15
#define MINCHAR 97
int main (void)
{
	int c, i, j;
	int fre[MAXCHAR];
	int maxvalue;
	for (i = MINCHAR; i < MAXCHAR; ++i){
		fre[i] = 0;
	}
	while ((c = getchar()) != EOF) {
		for (i = MINCHAR; i < MAXCHAR; ++i){
			if (c == i){
				++fre[i];
			}
		}
	}
	maxvalue = 0;
	for (i = MINCHAR; i < MAXCHAR; ++i)
		if (maxvalue < fre[i])
			maxvalue = fre[i];
	for (i = MAXHIST; i > 0; --i) {
		for (j = MINCHAR; j < MAXCHAR; ++j){
			if ((fre[j] * MAXHIST / maxvalue) >= i){
				printf(" *");
			}
			else{
				printf("  ");
			}
		}
		putchar('\n');
	}
	for (i = MINCHAR; i < MAXCHAR; ++i){
		putchar(' ');
		putchar(i);
	}
	putchar('\n');
}
