#include "main.h"
#include <stdio.h>
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
	printf("%d\n", _abs(100));
	printf("%d\n", _abs(-10));
	printf("%d\n", _abs(0));
	return (0);
}

/**
 * _abs - computes the asbolute of a number
 * @n: only argument
 * Description: takes one int argument and returns its absolute value
 * Return: always the absolute value
 */

int _abs(int n)
{
	int abs;

	if (n < 0)
	{
		abs = n * -1;
		return (abs);
	}
	else
	{
		abs = n;
		return (abs);
	}
}

