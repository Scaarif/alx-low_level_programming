#include "main.h"
/**
 * print_alphabet - print alphabet with new line at end
 * Description: takes no arguments and has no return value
 * Return: void
 */

void print_alphabet(void)
{
	char start = 'a';

	while (start <= 'z')
	{
		_putchar(start);
		start++;
	}
	_putchar('\n');
}

