#include "main.h"

/**
 * factorial - returns the factorial of a number n
 * @n: integer
 * Return: int factorial
 */

int factorial(int n)
{
	int fact;

	if (n < 0)
	{
		fact = -1;
	}
	else if (n == 0 || n == 1)
	{
		fact = 1;
	}
	else
	{
		fact = n * factorial(n - 1);
	}
	return (fact);
}

