#include <stdio.h>
#include <stdlib.h>
/**
 * main - prints number of arguments besides program name
 * @argc: arg count
 * @argv: args array
 * Return: 0 always
 */
int main(int argc, char **argv)
{
	(void) argv;
	if (argc > 0)
		printf("%d\n", (argc - 1));
	return (0);
}

