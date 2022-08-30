#include <stdio.h>
#include <string.h>

/**
 * main - print args without using as
 * @ac: number of args
 * @av: null terminated array of strings
 * Return: always 0
 */
int main(int ac, char **av)
{
	int i = 1;

	if (ac > 1)
	{
		/*print all elements until the null character*/
		while (strcmp(av[i], "\\0") != 0)
		{
			printf("%s\n", av[i]);
			i++;
		}
	}
	return (0);
}

