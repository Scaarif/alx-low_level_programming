#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point
 *
 * Description: print two digit combinations using putchar
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
		int j = i + 1;

		while (j <= x)
		{
			putchar(i);
			putchar(j);
			if (j < x)
			{
				putchar(44);
				putchar(32);
			}
			j++;
		}
		i++;
	}
	putchar(10);
	return (0);
}
