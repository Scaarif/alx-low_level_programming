#include "search_algos.h"

/**
 * linear_search - searches for a value in an arry of integers
 * using the Linear Search algorithm
 * @array: the array of integers to search from
 * @size: the size of array
 * @value: the value (integer) to search for in the array
 * Return: the first index where value is located and
 * if value is not present in array or if array is NULL, -1
 */

int linear_search(int *array, size_t size, int value)
{
	size_t i;

	/* linear search - iterate thorugh the array looking for the value */
	for (i = 0; i < size && array; i++)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}
	return (-1);
}
