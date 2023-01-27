#include "search_algos.h"

/**
 * min - returns the smaller of two integers
 * @a: integer one
 * @b: integer two
 * Return: the smaller of two integers
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
 * binary_search_ - searches for a value in a sorted array of integers using
 * Binary Search algorithm
 * @array: the array of integers to search from
 * @lower_b: the lower bound index (start search at lower_b)
 * @upper_b: the upper bound index (end search at lower_b)
 * @value: the value to search from in the array
 * Return: the index where value is located and -1 otherwise (
 * if array is NULL or value not in array)
 */

int binary_search_(int *array, size_t lower_b, size_t upper_b, int value)
{
	size_t mid;

	/* check if value == array[mid] and search right or left of subarray */
	while (lower_b <= upper_b && array)
	{
		print_array(array, lower_b, upper_b);
		mid = lower_b + (upper_b - lower_b) / 2;
		if (array[mid] == value)
			return (mid);
		else if (array[mid] > value) /* go left */
			upper_b = mid - 1;
		else /* go right */
			lower_b = mid + 1;
	}
	return (-1);
}

/**
 * exponential_search - searches for a value in an array of integers using
 * Exponential Search Algorithm
 * @array: pointer to the array to search from
 * @value: the value to search for
 * @size: the size of the array
 * Return: the location of value in array and -1 if not found
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1;

	/* check that array is defined (not null) */
	if (!array)
		return (-1);
	/* find the boundary/range within which value (potentially) resides */
	while (bound < size && array[bound] < value)
		bound *= 2;
	/* binary_search for value within established boundary */
	return (binary_search_(array, bound / 2, min(bound, size) - 1, value));
}
