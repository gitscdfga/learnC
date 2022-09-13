#include <stdio.h>
#define MAXLINE 1000
int newgetline(char line[], int maxvalue);
void copy(char to[], char from[]);

/* Remove trailing blanks and tabs from each line of input, and to delete entirely blank lines. */
int main(void)
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = newgetline(line, MAXLINE)) > 0)
		printf("%d %s", len, line);
		if (len > max){
			max = len;
			copy(longest, line);
		}
	if (max > 0)
		printf("%s", longest);
	return 0;
}

/* newgetline: get line in s and retrun lengths */
int newgetline(char s[], int lim)
{
	int c, i, j, k;
	j = 0;
	char l[MAXLINE];
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i){
		if (j < lim -2){
			l[j] = c;
			++j;
		}
	}
	if (c == '\n'){
		l[j] = c;
		++j;
		++i;
	}
	while (j > 0 && l[j - 1] == '\t' && l[j -1] == ' '){
		k = j - 1;
		s[k] = '\0'
		--j;
	}
	while (j > 0){
		--j;
		k = j;
		s[k] = l[j];
	}
	if (i > 1)
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
