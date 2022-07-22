#include "main.h"

/**
 * _isupper - check if a letter is uppercase
 * @c: int argument
 * Return: 1 if true, 0 otherwise
 */

int _isupper(int c)
{
	if (c <= 'Z' && c >= 'A')
		return (1);
	else
		return (0);
}
