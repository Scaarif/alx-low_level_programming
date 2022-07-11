#include "main.h"
#include <stdio.h>

int main(void)
{
	char *str;

	str = "My first strlen!";

	printf("n=%d\n", _strlen(str));
	return (0);
}

/**
 * _strlen - returns length of a string
 * @s: array pointer argument
 * Return: length of character array (string)
 */
int _strlen(char *s)
{
	int len = 0;
	char i = s[len];

	while (i != '\0')
	{
		len++;
		i = s[len];
	}
	return (len);
}
