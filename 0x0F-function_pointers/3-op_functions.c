#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * op_add - returns sum of a and b
 * @a: integer one
 * @b: integer two
 * Return: integer sum
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - returns difference between a and b
 * @a: integer one
 * @b: integer two
 * Return: integer difference
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - returns product of a and b
 * @a: integer one
 * @b: integer two
 * Return: integer product
 */
int op_mul(int a, int b)
{
	/*printf("mul: %d\n", a * b);*/
	return (a * b);
}

/**
 * op_div -integer divides a and b
 * @a: integer one
 * @b: integer two
 * Return: integer result
 */
int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	else
	{
		return (a / b);
	}
}

/**
 * op_mod - returns the modulo of a and b
 * @a: integer one
 * @b: integer two
 * Return: integer modulo
 */
int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	else
	{
		return (a % b);
	}
}

