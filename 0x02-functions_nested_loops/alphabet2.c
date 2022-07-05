#include "main.h"
#include <unistd.h>

/**
 * main - entry point
 *
 * Description: calls the print_alphabet and _putchar functions
 *
 * Return: always 0
 *
 */
int main(void)
{
	print_alphabet();
	return (0);
}

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

int _putchar(char c)
{
	return (write(1, &c, 1));
}

