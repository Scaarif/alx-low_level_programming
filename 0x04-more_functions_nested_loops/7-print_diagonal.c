#include "main.h"

/**
 * print_diagonal - print a diagonal line
 * @n: number of \ to print
 * Return: void
 */

void print_diagonal(int n)
{
	int i = 0, p, position;

	if (n > 0)
	{
		while (i < n)
		{
			position = i;
			p = 0;
			while (p < position)
			{
				_putchar(' ');
				p++;
			}
			_putchar('\\');
			_putchar('\n');
			i++;
		}
	}
	else
	{
		_putchar('\n');
	}

}
