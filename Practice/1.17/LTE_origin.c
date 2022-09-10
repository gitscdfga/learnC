#include <stdio.h>
#define MAXLINE 1000
int newgetline(char line[], int maxvalue);
void copy(char to[], char from[]);

/* print lines that are longer than 80 character */
int main (void)
{
	int len;				/* current line length */
	int max;				/* max line length */
	char line[MAXLINE];		/* save current input character */
	char longest[MAXLINE];	/* save longest input character */

	max = 0;
	while ((len = newgetline(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	printf("%s", longest);
	return 0;
}

/* newgetline:get the line in s and return lengths */
int newgetline(char s[], int lim)
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* copy: copy 'from' into 'to', assum 'to' is big enough */
void copy(char to[], char from[])
{
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
