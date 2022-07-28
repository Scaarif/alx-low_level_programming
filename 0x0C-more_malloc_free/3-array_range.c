#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * array_range - allocates memory for an array of integers
 * @min: min integer inclusive in range
 * @max: max integer in range, inclusive
 *Description: returns NULL  if min > max
 * Return: pointer to allocated array or NULL
 * if malloc fails
 */
int *array_range(int min, int max)
{
	int *ptr, i, size;

	if (min > max)
		return (NULL);
	size = (max - min) + 1;
	ptr = malloc(sizeof(int) * size);
	if (ptr == NULL)
	{
		return (NULL);
	}
	/* Initialize the elements: ordered ints from min to max */
	for (i = 0; i < size && min <= max; i++, min++)
		ptr[i] = min;
	return (ptr);
}


