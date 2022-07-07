#include "main.h"

/**
 * print_triangle - prints a # made triagle
 * @n: number of # to print
 * Return: void
 */

void print_triangle(int n)
{
	int i = 0, p, position, hashes;

	if (n > 0)
	{
		while (i < n)
		{
			position = n - i - 1; /*else start i at 1 not 0*/
			p = 0;
			while (p < position)
			{
				_putchar(' ');
				p++;
			}
			hashes = i;
			while (hashes >= 0)
			{
				_putchar('#');
				hashes--;
			}
			_putchar('\n');
			i++;
		}
	}
	else
	{
		_putchar('\n');
	}

}
