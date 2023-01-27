#include "search_algos.h"

/**
 * interpolation_search - searches for a value in sorted array of integers
 * using the Interpolation Algorithm
 * @array: pointer to the array in which to search
 * @size: size (no of elems) of array
 * @value: the value to search for
 * Return: the first index where value is located and -1 otherwise (
 * if array is NULL or value is not found)
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t pos, lower_b = 0, upper_b = size - 1;

	/* check that array is defined */
	if (!array)
		return (-1);
	while (lower_b <= upper_b)
	{
		pos = lower_b + (((double)(upper_b - lower_b) / (array[upper_b]
						- array[lower_b])) * (value - array[lower_b]));
		if (pos >= size)
			printf("Value checked array[%ld] is out of range\n", pos);
		else
			printf("Value checked array[%ld] = [%d]\n", pos, array[pos]);
		if (array[pos] == value)
			return (pos);
		if (value < array[pos])
			upper_b = pos - 1;
		else
			lower_b = pos + 1;
	}
	/* array exhausted or of size 0 */
	return (-1);
}
