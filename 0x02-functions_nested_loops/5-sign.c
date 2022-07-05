#include "main.h"

/**
 * main - entry point
 *
 * Description: calls the print_sign and _putchar functions
 *
 * Return: always 0
 *
 */
int main(void)
{
	print_sign(100);
	print_sign(10);
	print_sign(0);
	return (0);
}

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
		_putchar(',');
		_putchar(' ');
		_putchar('1');
		_putchar('\n');
		return (1);
	}
	else if (n == 0)
	{
		_putchar('0');
		_putchar(',');
		_putchar(' ');
		_putchar('0');
		_putchar('\n');
		return (0);
	}
	else
	{
		_putchar('-');
		_putchar(',');
		_putchar(' ');
		_putchar('-');
		_putchar('1');
		_putchar('\n');
		return (-1);
	}
}


