#include "search_algos.h"

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
 * binary_search - searches for a value in a sorted array of integers using
 * Binary Search algorithm
 * @array: the array of integers to search from
 * @size: the size of the array
 * @value: the value to search from in the array
 * Return: the index where value is located and -1 otherwise (
 * if array is NULL or value not in array)
 */

int binary_search(int *array, size_t size, int value)
{
	size_t mid, lower_b = 0, upper_b = size - 1;

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
