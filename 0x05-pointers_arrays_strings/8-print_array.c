#include "main.h"
#include <stdio.h>

/**
 * print_array - prints n elements in an array
 * @a: array of integers
 * @n: number of elememnts to print
 * Return: void
 */
void print_array(int *a, int n)
{
	int i = 0;

	if (n > 0)
	{
		while (i < (n - 1))
		{
			printf("%d, ", a[i]);
			i++;
		}
		if (i == (n - 1))
			printf("%d\n", a[i]); /*exclude space and comma after last element*/
	}
	else
	{
		printf("\n");
	}
}
