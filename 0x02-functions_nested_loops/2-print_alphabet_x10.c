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
	int i = 0;
	
	while (i < 10)
	{
		print_alphabet_x10();
		i++;
	}
	return (0);
}

/**
 * print_alphabet_x10 - print alphabet with new line at end
 * Description: takes no arguments and has no return value
 * Return: void
 */

void print_alphabet_x10(void)
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

