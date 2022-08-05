#include <stdio.h>
#define MAXHIST 15
int main (void)
{
	int c, i, j;
	int maxvalue;
	int nc[2];
	for (i = 0; i < 2; ++i)
		nc[i] = 0;
	while ((c = getchar()) != EOF){
		if (c == 'a')
			++nc[0];
		else
			++nc[1];
	}
	maxvalue = 0;
	for (i = 0; i < 2; ++i)
		if (maxvalue < nc[i])
			maxvalue = nc[i];
	for (i = MAXHIST; i > 0; --i){
		for (j = 0; j < 2; ++j){
			if ((nc[j] * MAXHIST / maxvalue) >= i)
				printf(" * ");
			else
				printf("   ");
		}
		putchar('\n');
	}
	printf(" a b\n");
}
