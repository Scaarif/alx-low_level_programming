#include "main.h"
#include <stdio.h>

int main(void)
{
	char *str;

	str = "I do not fear computers. I fear the lack of them - Isaac Asimov";
	print_rev(str);
	return (0);
}

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
