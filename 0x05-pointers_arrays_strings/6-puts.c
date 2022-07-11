#include "main.h"
#include <stdio.h>

int main(void)
{
	char *str;

	str = "0123456789";
	puts2(str);
	return (0);
}

/**
 * puts2 - prints every other character of a string
 * Description; starts with the first characetr
 * @str: string argument
 * Return: void
 */
void puts2(char *str)
{
	int len = 0;

	while (str[len] != '\0')
	{
		_putchar(str[len]);
		len += 2;
	}
	_putchar('\n');
}
