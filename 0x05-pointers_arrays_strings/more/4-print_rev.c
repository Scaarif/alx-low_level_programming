#include "main.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char *str;

	str = "I do not fear computers. I fear the lack of them. - Isaac Asimov";
	print_rev(str);
	puts(str);
	return (0);
}
/**
 * print_rev - print a string in reverse
 * Description: only use _putchar
 * Return: nothing
 */

void print_rev(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++);
	for (; i >= 0; i--)
		_putchar(s[i]);
	_putchar('\n');
}


