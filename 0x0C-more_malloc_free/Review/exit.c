#include <stdio.h>
#include <stdlib.h>
/**
 * main - prints program name
 * @argc: arg count
 * @argv: args array
 * Return: always EXIT_SUCCESS
 */

int main(int argc, char **argv)
{
	if (argc > 0)
		printf("%s\n", *argv);
	exit(98);
}

