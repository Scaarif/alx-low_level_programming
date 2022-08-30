#include <stdio.h>
#include <stdlib.h>
/**
 * main - executed by a second program; 
 * echoes its cmd line args, one per line
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	int j;

	for (j = 0; argv[j] != NULL; j++)/*argv always ends with NULL in execve()*/
		printf("argv[%d]: %s\n", j, argv[j]);
	exit(EXIT_SUCCESS);
}

