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
	int x = 48 + 9;

	while (i <= x)
	{
		putchar(i);
		if (i < x)
			putchar(44);
			putchar(32);
		i++;
	}
	putchar(10);
	return (0);
}
