#include "main.h"

/**
 * print_alphabet_x10 - print alphabet with new line at end
 * Description: takes no arguments and has no return value
 * Return: void
 */

void print_alphabet_x10(void)
{
	int i = 0;

	while (i < 10)
	{
		char start = 'a';

		while (start <= 'z')
		{
			_putchar(start);
			start++;
		}
		_putchar('\n');
		i++;
	}

}


