#include "holberton.h"

/**
 * reverse_array - reverse array contents
 * @a: the array of integers
 * @n: no of integers in the array
 * Return: nothing
 */

void reverse_array(int *a, int n)
{
	int i;
	int j;

	for (i = 0; i < (n / 2); i++)
	{
		j = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = j;
	}
}
