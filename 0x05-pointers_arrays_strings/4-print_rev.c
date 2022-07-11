#include "main.h"

/**
 * print_rev - prints a string in reverse to stdout
 * @s: string argument
 * Return: void
 */
void print_rev(char *s)
{
	int len = _strlen(s);

	while (len >= 0)
	{
		_putchar(s[len]);
		len--;
	}
	_putchar('\n');
}
