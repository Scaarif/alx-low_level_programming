#include "main.h"

/**
 * print_last_digit - prints last digit of a number
 * @n: only argument
 * Description: returns the last digit in the argument provided
 * Return: last digit
 */

int print_last_digit(int n)
{
	int last = n % 10;

	_putchar(last + '0');
	return (last);
}


