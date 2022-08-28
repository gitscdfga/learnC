#include <stdio>
#define MAXLINE 1000
int newgetline(char line[], int maxline);
void copy(char to[], char from[]);
/* revise program that longest-line for print abitrary line */

int main(void)
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = newgetline(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	if (max > 0)
		printf("%s", longest);
	return 0;
}

/* newgetline: get the line in s and return lengths */
int newgetline(char s[], int limt)
{
	int c, i;

	for (i = 0; i < limt -1 && (c = getchar()) != EOF && c != '\n', ++i)
		s[i] = c;
	if (c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* copy: copy 'from' into 'to'; assume 'to' is big enough */
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
