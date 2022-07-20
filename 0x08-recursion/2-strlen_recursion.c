#include "main.h"

/**
 * _strlen_recursion - returns length of a string
 * @s: string
 * Return: int length
 */

int _strlen_recursion(char *s)
{
	int len = 0;

	if (*(s + len) == '\0')
		return (len);
	len++;
	return (len + _strlen_recursion(s + 1));
}
