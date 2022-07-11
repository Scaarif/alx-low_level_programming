#include "main.h"

/**
 * print_rev - prints a string in reverse to stdout
 * @s: string argument
 * Return: void
 */
void print_rev(char *s)
{
	int len = 0, a_len;
	char i = s[len];

	while (i != '\0')
	{
		len++;
		i = s[len];
	}

	a_len = len - 1; /*exclude the '\0' character */
	while (a_len >= 0)
	{
		_putchar(s[a_len]);
		a_len--;
	}
	_putchar('\n');
}
