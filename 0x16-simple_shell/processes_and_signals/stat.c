#include "main.h"
/**
 * main - stat (which returns the status of a file) example 1
 * Return: Nothing
 */

int main(int ac, char **av)
{
	unsigned int i;
	struct stat st;

	if (ac < 2)
	{
		printf("Usage: %s path_to_file ..\n", av[0]);
		return (1);
	}
	i = 1;
	while (av[i])
	{
		printf("%s:", av[i]);
		if (stat(av[i], &st) == 0)/*stat returns 0 if ok and -1 otherwise*/
			printf(" Found\n");
		else
			printf(" NOT FOUND\n");
		i++;
	}
	return (0);
}

