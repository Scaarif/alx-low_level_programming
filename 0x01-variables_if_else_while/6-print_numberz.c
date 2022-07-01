#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point
 *
 * Description: print single digit numbers starting from zero using putchar
 *
 * Return: always 0 (success)
 *
 */
int main(void) 
{
	int i = 48;
	int x = 48 + 10;

	while (i < x)
	{
		putchar(i);
		i++;
	}
	putchar(10);
	return (0);
}
