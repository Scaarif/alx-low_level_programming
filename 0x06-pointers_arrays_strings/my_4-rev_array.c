#include "main.h"

/**
 * reverse_array - reverse array contents
 * @a: the array of integers
 * @n: no of integers in the array
 * Return: nothing
 */
void reverse_array(int *a, int n)
{
	/* take the contents and reverse their order - last is first*/
	/* make a copy to hold the contents*/
	int b[n], i, j;

	for (i = 0; i < n; i++)
		b[i] = a[i];
	/* now reverse the integers in a*/
	j = n - 1;
	for (i = 0; i < n && j >= 0; i++, j--)
		a[i] = b[j];

}

