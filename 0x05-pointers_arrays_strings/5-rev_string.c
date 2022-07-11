#include "main.h"
#include <stdio.h>

int main(void)
{
	char str[10] = "My School";

	printf("%s\n", str);
	rev_string(str);
	return (0);
}

/**
 * rev_string - prints a string in reverse to stdout
 * @s: string argument
 * Return: void
 */
void rev_string(char *s)
{
	int len = _strlen(s);

	while (len >= 0)
	{
		_putchar(s[len]);
		len--;
	}
	_putchar('\n');
}
