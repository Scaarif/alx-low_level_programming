#include "main.h"

/**
 * print_last_digit - prints last digit of a number
 * @n: only argument
 * Description: returns the last digit in the argument provided
 * Return: last digit
 */

int print_last_digit(int n)
{
	int nv;

	if (n < 0)
	{
		nv = -1 * (n % 10);
		_putchar(nv + '0');
		return (nv);
	}
	else
	{
		nv = n % 10;
		_putchar(nv + '0');
		return (nv);
	}

}
