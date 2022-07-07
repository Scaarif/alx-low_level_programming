#include "main.h"

/**
 * print_numbers - print numbers 0 to 9
 * Description: takes no arguments
 * Return: void
 */

void print_numbers(void)
{
	int a = 0;

	while (a <= 9)
	{
		_putchar(a + '0');
		a++;
	}
	_putchar('\n');
}
