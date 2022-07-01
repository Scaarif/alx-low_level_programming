#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point
 *
 * Description: print two, two digit combinations using putchar
 *
 * Return: always 0 (success)
 *
 */
int main(void)
{
	int i, j, k, l, x;

	i = j = k = l = 48;
	x = 48 + 9;

	while (i <= x)
	{
		/*int j = i + 1;*/

		while (j <= x)
		{
			/*int k = j + 1;*/

			while (k <= x)
			{
				while (l <= x)
				{
					if (i == j == k == l == 48)
						++l;
					putchar(i);
					putchar(j);
					putchar(44);
					putchar(k);
					putchar(l);
					putchar(44);
					putchar(32);
					l++;
				}
				k++;
			}
			j++;
		}
		i++;
	}
	putchar(10);
	return (0);
}
