#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point
 *
 * Description: print single digit numbers starting from zero
 *
 * Return: always 0 (success)
 *
 */
int main(void) 
{
	int i = 0;

	while (i < 10)
	{
		printf("%d", i);
		i++;
	}
	printf("\n");
}
