#include "main.h"

/**
 * _isalpha - check if a char is alphabet
 * @c: only argument
 * Description: takes one int argument and has no return an int
 * Return: 1 or 0 for true and false
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}


