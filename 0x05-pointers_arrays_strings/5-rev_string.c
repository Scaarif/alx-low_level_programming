#include "main.h"

/**
 * rev_string - prints a string in reverse to stdout
 * @s: string argument
 * Return: void
 */
void rev_string(char *s)
{
	int len = 0;
	char i = s[len];

	while (i != '\0')
	{
		len++;
		i = s[len];
	}

	len--;
	while (len >= 0)
	{
		_putchar(s[len]);
		len--;
	}
	_putchar('\n');
}
