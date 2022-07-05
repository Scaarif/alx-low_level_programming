#include "main.h"

/**
 * print_sign - print the sign of a number
 * @n: only argument
 * Description: takes one int argument and returns an int
 * Return: 1, 0 or -1 for positive, zero and negative respectively
 */

int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n == 0)
	{
		_putchar('0');
		return (0);
	}
	else
	{
		_putchar('-');
		return (-1);
	}
}


