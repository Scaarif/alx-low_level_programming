#include "main.h"

/**
 * _getline1 - reads a line from stream
 * @s: pointer to string buffer into which to read
 * @lim: pointer to buffer size limit
 * @fd: stream to read from
 * Return: no of characters read
 */
int _getline1(char *s, int lim, int fd)
{
	int n_read;

	n_read = read(fd, s, lim);
	if (n_read < 0)
	{
		unix_error("read error");
		return (-1);
	}
	return (n_read);
}

/**
 * _getline - reads a line from stream
 * @s: the buffer into which to read
 * @lim: the size limit
 * Return: size of buffer
 */
int _getline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return (i);
}

/**
 * copy - copy 'from' to 'to', assuming 'to' is big enough
 * @from: string to copy
 * @to: buffer to copy into
 * Return: Nothing
 */
void copy(char to[], char from[])
{
	int i = 0;

	while ((to[i] = from[i]) != '\0')
		i++;
}

/* print longest input line */
int main(void)
{
	int len, lim = PATH_S;/*current line length*/
	int max;/*max length seen so far*/
	char line[PATH_S];/*current input line*/
	char longest[PATH_S];/*longest line saved here*/

	max = 0;
	/*if from a file, OPEN file first, to get fd*/
	write(1, "shell_y$: ", 11);
	len = _getline1(line, lim, STDIN_FILENO);
	printf("_getline1 at %d: %s", len, line);
	while ((len = _getline(line, PATH_S)) > 0)
	{
		if (len > max)
		{
			max = len;
			copy(longest, line);
		}
		if (max > 0)/*there was a line*/
			printf("_getline at %d: %s", max, longest);
	}
	return (0);
}


