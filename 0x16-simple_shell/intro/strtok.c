#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 1024

int main(int argc, char *argv[])
{
	char *str1, *token, arr[BUFFER];
	int j, i = 0, k;

	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s string delim\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	for (j = 1, str1 = argv[1]; ; j++, str1 = NULL)
	{
		token = strtok(str1, argv[2]);/*str, delim*/
		if (token == NULL)
			break;
		printf("%d: %s\n", j, token);
		/* append the array of tokens */
		for (k = 0; i <= BUFFER && token[k] != '\0'; i++, k++)
		{
			if (token[k] != ' ' && token[k] != *(argv[2]))/*ignore spaces and delim char*/
			arr[i] = token[k];
		}
		arr[i++] = '\0'; /*terminate each token*/
	}
	for (k = 0; k < i - 1;)
	{
		for (; arr[k] != '\0'; k++)
			putchar(arr[k]);
		putchar('\n');
		k++;
	}
	exit(EXIT_SUCCESS);
}

