#include <stdio.h>
#include <stdlib.h>
/**
 * main - prints number of arguments besides program name
 * @argc: arg count
 * @argv: args array
 * Return: always EXIT_SUCCESS
 */
int main(int argc, char **argv)
{
	if (argc > 0)
		printf("%d\n", --argc);
	exit(EXIT_SUCCESS);
}

