#include "main.h"

/**
 * _islower - check if a char is lowercase
 * @c: only argument
 * Description: takes one int argument and has no return an int
 * Return: 1 or 0 for true and false
 */

int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}


