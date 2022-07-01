#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: prints two two combinations
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int i, j, k, l, a, b, c, d;

	for (i = 0; i <= 9; i++)
	{
		a = i + '0';
		for (j = 0; j <=8; j++)
		{
			b = j + '0';
			for (k = i; k <= 9; k++)
			{
				c = k + '0';
				for (l = k + 1; l <= 9; l++)
				{
					d = l + '0';
					putchar(a);
					putchar(b);
					putchar(' ');
					putchar(c);
					putchar(d);

					if (i == 9 && j == 8 && k == 9 && l == 9)
					{
						break;
					}
					else
					{
						putchar(',');
						putchar(' ');
					}
				}
			}
		}
	}

	putchar('\n');

	return (0);
}