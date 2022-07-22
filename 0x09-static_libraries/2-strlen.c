#include "main.h"

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
