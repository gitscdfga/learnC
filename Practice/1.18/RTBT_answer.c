#include <stdio.h>
#define MAXLINE 1000
int newgetline(char line[], int maxvalue);
void copy(char to[], char from[]);
int removeblank(char s[]);

/* Remove trailing blanks and tabs from each line of input, and to delete entirely blank lines. */
int main(void)
{
	char line[MAXLINE];

	while (newgetline(line, MAXLINE) > 0)
		if (removeblank(line) > 0)
			printf("%s", line);
	return 0;
}

/* newgetline: get line in s and retrun lengths */
int newgetline(char s[], int lim)
{
	int c, i;
	for (i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* copy: copy 'from' into 'to'; assum 'to' is big enough */
void copy(char to[], char from[])
{
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}

/* removeblank: remove trailing blanks and tabs from character string s */
int removeblank(char s[])
{
	int i;

	i = 0;
	while (s[i] != '\n')	/* find newline character		*/
		++i;
	--i;					/* back off from '\n'			*/
	while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
		--i;
	if (i >= 0) {			/* is it a nonblank line?		*/
		++i;
		s[i] = '\n';		/* put newline character back	*/
		++i;
		s[i] = '\0';		/* terminate the string			*/
	}
	return i;
}
