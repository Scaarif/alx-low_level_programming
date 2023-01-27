#include "search_algos.h"
#include <math.h>

/**
 * min - returns the smaller of two integers
 * @a: integer one
 * @b: integer two
 * Return: the samller of a and b
 */
size_t min(size_t a, size_t b)
{
	if (a > b)
		return (b);
	return (a);
}

/**
 * print_array - prints a part of an array
 * @array: the array whose sub-array to print
 * @start: starting index
 * @end: stopping index
 * Return: Nothing
 */

void print_array(int *array, size_t start, size_t end)
{
	printf("Searching in array: ");
	for (; start < end; start++)
		printf("%d, ", array[start]);
	printf("%d\n", array[end]);
}

/**
 * jump_search - searches for a value in a sorted array of integers using
 * Jump Search algorithm
 * @array: pointer to the array of integers to search from
 * @size: the size of the array
 * @value: the value to search from in the array
 * Return: the index where value is located and -1 otherwise (
 * if array is NULL or value not in array)
 */

int jump_search(int *array, size_t size, int value)
{
	size_t step, i, lower_b = 0;

	if (!array)
		return (-1);
	step = sqrt(size);
	/* get the block in which value (potentially) recides */
	while (value > array[min(step, size) - 1])
	{
		printf("Value checked array[%ld] = [%d]\n", lower_b, array[lower_b]);
		i = min(step, size);
		lower_b = step;
		step += sqrt(size);
		/* if lower_b > size, value doesn't exist in array */
		if (lower_b > size)
		{
			i = lower_b - (step - lower_b);
			printf("Value found between indexes [%ld] and [%ld]\n", i, lower_b);
			printf("Value checked array[%ld] = [%d]\n", i, array[i]);
			return (-1);
		}
	}
	/* Linear search the block for value */
	if (lower_b == 0)
		printf("Value checked array[%ld] = [%d]\n", lower_b, array[lower_b]);
	i = lower_b + sqrt(size);
	printf("Value found between indexes [%ld] and [%ld]\n", lower_b, i);
	while (value > array[lower_b])
	{
		printf("Value checked array[%ld] = [%d]\n", lower_b, array[lower_b]);
		lower_b++;
		/* if lower_b exceeds step, value not in block/array */
		if (lower_b == min(step, size))
			return (-1);
	}
	if (array[lower_b] == value)
	{
		printf("Value checked array[%ld] = [%d]\n", lower_b, array[lower_b]);
		return (lower_b);
	}
	return (-1); /* array[lower_b] != value & therefore value not in block */
}
