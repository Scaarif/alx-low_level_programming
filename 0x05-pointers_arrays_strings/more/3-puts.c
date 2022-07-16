#include "main.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char *str;

	str = "My first strlen!";
	_puts(str);
	puts(str);
	return (0);
}
/**
 * _puts - print a string to stdout
 * Description: only use _putchar
 * Return: nothing
 */

void _puts(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		_putchar(s[i]);
	_putchar('\n');
}


