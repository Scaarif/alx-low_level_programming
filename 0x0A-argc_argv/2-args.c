#include <stdio.h>
#include <stdlib.h>
/**
 * main - prints all arguments received
 * @argc: arg count
 * @argv: args array
 * Return: always EXIT_SUCCESS
 */

int main(int argc, char **argv)
{
	while (argc--) /*i.e. while argc != 0 starting at argc--*/
		printf("%s\n", *argv++); /*print string, starting at argv[1]*/
	exit(EXIT_SUCCESS);
}

