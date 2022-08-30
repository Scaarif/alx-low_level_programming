#include <stdio.h>

int main(void)
{
	/*getline takes **lineptr, *len, *stream as args*/
	char *line = NULL;/* &line = lineptr*/
	size_t len = 0; /*size of line*/
	size_t chars;

	printf("$ ");
	chars = getline(&line, &len, stdin);/*reading from stdin and storing in *line*/
	if (chars)
		printf("\n%s\n", line);
	return (0);
}

