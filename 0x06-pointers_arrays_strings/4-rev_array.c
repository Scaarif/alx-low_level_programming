#include "holberton.h"

/**
 * reverse_array - reverse array contents
 * @a: the array of integers
 * @n: no of integers in the array
 * Return: nothing
 */
void reverse_array(int *a, int n)
{
	int tmp, index;

	for (index = n - 1; index >= n / 2; index--)
	{
		tmp = a[n - 1 - index];
		a[n - 1 - index] = a[index];
		a[index] = tmp;
	}
}
