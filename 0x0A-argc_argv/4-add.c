#include <stdio.h>
#include <stdlib.h>
/**
 * main - adds two numbers
 * Description: prints result followed by newline
 * prints Error if less arguments or letters are received
 * @argc: arg count
 * @argv: args array
 * Return: 1 if error, else 0
 */
int main(int argc, char **argv)
{
	int i = argc - 1, sum = 0;
	char *s;

	if (argc == 1) /*only prog name provided */
	{
		printf("%d\n", sum);
		return (0);
	}
	else
	{
		while (argc > 1)
		{
			s = argv[i];
			if (*s < '0' || *s > '9')
			{
				printf("Error\n");
				return (1);
			}
			sum += atoi(argv[i]);
			i--;
			argc--;
		}
		printf("%d\n", sum);
		return (0);
	}
}

