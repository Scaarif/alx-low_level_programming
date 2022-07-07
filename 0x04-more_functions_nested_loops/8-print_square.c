#include "main.h"

/**
 * print_square - prints a square
 * @n: size of square
 * Return: void
 */

void print_square(int n)
{
	int i = 0;

	while (i < n)
	{
		int a = 0;

		while (a < n)
		{
			_putchar('#');
			a++;
		}
		_putchar('\n');
		i++;
	}
}
