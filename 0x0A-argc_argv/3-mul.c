#include <stdio.h>
#include <stdlib.h>
/**
 * main - multiplies two numbers
 * Description: prints result followed by newline
 * prints Error if less arguments are received
 * @argc: arg count
 * @argv: args array
 * Return: 1 if error, else 0
 */
int main(int argc, char **argv)
{
	if (argc < 3)
	{
		printf("Error\n");
		return (1);
	}
	printf("%d\n", atoi(argv[1]) * atoi(argv[2]));
	return (0);
}

