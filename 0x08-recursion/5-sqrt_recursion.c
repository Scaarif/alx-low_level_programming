#include "main.h"

/**
 * helper - helper function to solve _sqrt_recursion
 * @c: number to determine if square root
 * @i: incrementor to compare against `c`
 * Return: square root if natural square root, or -1 if none found
 */

int helper(int c, int i)
{
	int square;

	square = i * i;
	if (square == c)
		return (i);
	else if (square < c)
		return (helper(c, i + 1));
	else
		return (-1);
}

/**
 * _sqrt_recursion - returns natural sqrt of a number
 * @n: integer
 * Return: If no natural square root, return -1. Else return natural
 * square root
 */

int _sqrt_recursion(int n)
{
	return (helper(n, 1));
}

