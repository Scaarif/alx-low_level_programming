#include "main.h"
#include <stdio.h>

int main(void)
{
	print_number(8);
	print_number(0);
	print_number(-1);
	_putchar('\n');
	return (0);
}
/**
 * print_number - print number
 * @n: integer to print
 * Return: void
 */

void print_number(int n)
{
	_putchar(n + '0');
}
