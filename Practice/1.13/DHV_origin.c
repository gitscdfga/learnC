#include <stdio.h>
#define MAXHIST 15
#define MAXWORD 11
#define IN 1
#define OUT 0
/* print a histogram with vertical */
int main (void) 
{
	int c, nc, i, j, state;
	int ovflow;
	int maxvalue;
	int wl[MAXWORD];

	nc = 0;
	state = OUT;
	ovflow = 0;
	for (i = 1; i < MAXWORD; ++i) {
		wl[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n'){
			state = OUT;
			if (nc > 0){
				++wl[nc];
			}
			nc = 0;
		} else {
			if (state == OUT){
				state = IN;
				nc = 1;
			} else {
				++nc;
			}
		}
	}

	maxvalue = 0;
	for (i = 1; i < MAXWORD; ++i) {
		if (maxvalue < wl[i])
			maxvalue = wl[i];
	}

	for (i = MAXHIST; i > 0; --i) {
		for (j = 1; j < MAXWORD; ++j) {
			if ((wl[j] * MAXHIST / maxvalue) >= i)
				printf(" * ");
			else
				printf("   ");
		}
		putchar('\n');
	}
	for (i = 1; i < MAXWORD; ++i) {
		printf(" %d ", i);
	}
	putchar('\n');

	if (ovflow > 0)
		printf("There is %d words >= %d\n", ovflow, MAXWORD);
}
