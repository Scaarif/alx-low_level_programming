#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point
 *
 * Description: print three digit combinations using putchar
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
			int k = j + 1;

			while (k <= x)
			{
				putchar(i);
				putchar(j);
				putchar(k);
				putchar(44);
				putchar(32);
				k++;
			}
			j++;
		}
		i++;
	}
	putchar(10);
	return (0);
}
