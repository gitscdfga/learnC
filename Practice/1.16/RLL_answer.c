#include <stdio.h>
#define MAXLINE 1000
int newgetline(char line[], int maxvalue);
void copy(char to[], char from[]);
/* revise the main routine for longest-line program */

int main(void)
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = newgetline(line, MAXLINE)) > 0){
		printf("%d %s", len, line);
		if (len > max){
			max = len;
			copy(longest, line);
		}
	}
	if (max > 0)
		printf("%s", longest);
	return 0;
}

/* newgetline: this function is a new, that get more than more characters in array 's'*/
int newgetline(char s[], int lim)
{
	int c, i, j;
	j = 0;
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i){
		if (j < lim -2){
			s[j] = c;
			++j;
		}
	}
	if (c == '\n'){
		s[j] = c;
		++j;
		++i;
	}
	s[j] = '\0';
	return i;
}

/* copy: copy the 'from' to 'to', assum 'to' is enough big */
void copy(char to[], char from[])
{
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
