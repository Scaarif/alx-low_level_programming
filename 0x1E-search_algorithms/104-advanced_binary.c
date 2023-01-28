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
 * binary_search_a - actual binary search
 * @array: pointer to the array of integers
 * @lower_b: the lower bound index
 * @upper_b: the upper bound index
 * @value: the value to search for
 * Return: the location of value in array
 */
int binary_search_a(int *array, size_t lower_b, size_t upper_b, int value)
{
	size_t mid, first_pos;

	if (lower_b > upper_b)
		return (-1);
	print_array(array, lower_b, upper_b);
	mid = lower_b + (upper_b - lower_b) / 2;
	if (array[mid] == value)
	{
		first_pos = mid;
		/* find the first occurrence of value (backwards) */
		while (array[first_pos] == value)
		{
			first_pos--;
		}
		if (first_pos + 1 != mid)
		{
			print_array(array, lower_b, mid);
			print_array(array, first_pos + 1, mid);
		}
		return (++first_pos);
	}
	else if (array[mid] > value) /* go left */
		return (binary_search_a(array, lower_b, mid - 1, value));
	else /* go right */
		return (binary_search_a(array, mid + 1, upper_b, value));
}

/**
 * advanced_binary - searches for a value in a sorted array of integers using
 * Binary Search algorithm (MUST use recursion)
 * @array: the array of integers to search from
 * @size: the size of the array
 * @value: the value to search from in the array
 * Return: the index where first occurence of value is located and -1
 * otherwise (if array is NULL or value not in array)
 */

int advanced_binary(int *array, size_t size, int value)
{
	size_t lower_b = 0, upper_b = size - 1;

	/* check if value == array[mid] and search right or left of subarray */
	if (!array)
		return (-1);
	return (binary_search_a(array, lower_b, upper_b, value));
}
