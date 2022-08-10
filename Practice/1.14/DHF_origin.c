#include <stdio.h>
#define BIGCHAR 123
#define MAXHIST 15
int main (void)
{
	int c, i, j;
	int fre[BIGCHAR];
	int maxvalue;
	for (i = 97; i < BIGCHAR; ++i)
		fre[i] = 0;
	while ((c = getchar()) != EOF) {
		for (i = 97; i < BIGCHAR; ++i){
			if (c == i)
				++fre[i];
		}
	}
	maxvalue = 0;
	for (i = 97; i < BIGCHAR; ++i)
		if (maxvalue < fre[i])
			maxvalue = fre[i];
	for (i = MAXHIST; i > 0; --i) {
		for (j = 22; j < BIGCHAR; ++j){
			if ((fre[j] * MAXHIST / maxvalue) < i)
				printf("  ");
			else
				printf(" *");
		}
		putchar('\n');
	}
	for (i = 97; i < BIGCHAR; ++i){
		putchar(' ');
		putchar(i);
	}
	putchar('\n');
}
