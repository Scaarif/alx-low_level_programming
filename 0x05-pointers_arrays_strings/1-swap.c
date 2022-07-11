#include "main.h"
#include <stdio.h>

int main(void)
{
	int a, b;

	a = 98;
	b = 42;

	printf("a=%d, b=%d\n", a, b);
	swap_int(&a, &b); /*memory addresses of a and b are the input parameters*/
	printf("a=%d, b=%d\n", a, b);
	return (0);
}

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
