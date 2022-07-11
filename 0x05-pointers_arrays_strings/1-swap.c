#include "main.h"


/**
 * swap_int - swaps values of two integers
 * @a: pointer to integer one
 * @b: pointer to integer two
 * Return: void
 */
void swap_int(int *a, int *b)
{
	int c = *a; /*hold value of first integer*/
	*a = *b;
	*b = c;
}
