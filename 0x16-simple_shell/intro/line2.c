#include <stdio.h>
#define MAXLINE 1000
/* _getline - reads a line into s, and returns its length */
int _getline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n')
		s[i] = c, ++i;
	s[i] = '\0';
	return (i);
}

/* copy - copies 'from' into 'to'; assume 'to' is big enough to hold 'from'*/
void copy(char to[], char from[])
{
	int i = 0;

	while ((to[i] = from[i]) != '\0')
		++i;
}	

/* main - print longest line */
int main(void)
{
	int len, max = 0;
	char line[MAXLINE], longest[MAXLINE];
	
	while ((len = _getline(line, MAXLINE)) > 0)
	{
		if (len > max)
		{
			max = len;
			copy(longest, line);
		}
	}
	if (max > 0)
		printf("longest line:\n%s\n", longest);
	return (0);
}


