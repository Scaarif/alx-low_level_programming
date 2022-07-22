#include "main.h"

/**
 * _puts - prints a string to stdout
 * @str: string argument
 * Return: void
 */
void _puts(char *str)
{
	int len = 0;
	char i = str[0];

	while (i != '\0')
	{
		_putchar(str[len]);
		len++;
		i = str[len];
	}
	_putchar('\n');
}
