#include "main.h"
#include <stdio.h>

/**
 * prints the sum of two diagonals of a square matrix
 * @a: the matrix
 * size: size of matrix
 * Returns: Nothing
 */
void print_diagsums(int *a, int size)
{
	int i = 0, sum1 = 0, sum2 = 0, actual_size;

	i = 0;
	actual_size = size * size;
	while (i < actual_size)
	{
		if (i % (size + 1) == 0)
			sum1 += a[i];
		i++;
	}
	printf("%d, ", sum1);

	i = 0;
	while (i < actual_size)
	{
		if (i % (size - 1) == 0 && i != (actual_size - 1) && i != 0)
			sum2 += a[i];
		i++;
	}
	printf("%d\n", sum2);
}



