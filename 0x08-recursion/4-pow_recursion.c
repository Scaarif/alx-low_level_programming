#include "main.h"

/**
 * _pow_recursion - returns the y power of x
 * @x: integer one
 * @y: integer two
 * Return: integer power
 */

int _pow_recursion(int x, int y)
{
	int pow;

	if (y < 0)
	{
		pow = -1;
	}
	else if (y == 0)
		pow = 1;
	else if (y == 1)
		pow = x;
	else
	{
		pow = x * _pow_recursion(x, y - 1);
	}
	return (pow);
}

