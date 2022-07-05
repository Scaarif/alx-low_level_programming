#include "main.h"

/**
 * _abs - computes the asbolute of a number
 * @n: only argument
 * Description: takes one int argument and returns its absolute value
 * Return: always the absolute value
 */

int _abs(int n)
{
	int abs;

	if (n < 0)
	{
		abs = n * -1;
		return (abs);
	}
	else
	{
		abs = n;
		return (abs);
	}
}

