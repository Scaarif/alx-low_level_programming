#include "main.h"

/**
 * puts_half - prints 2nd half of string to stdout
 * @s: string argument
 * Return: void
 */
void puts_half(char *s)
{
	int len = _strlen(s);
	int half;

	if (len % 2 == 0)
		half = len / 2;
	else
		half = (len - 1) / 2;
	while (half < len)
	{
		_putchar(s[half]);
		half++;
	}
	_putchar('\n');
}
