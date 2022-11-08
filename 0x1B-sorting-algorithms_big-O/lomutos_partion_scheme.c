#include "sort.h"

/**
 * size - returns the size of the array
 * @array: the array
 * Return: size of array
 */
int size(int array[])
{
	int size = 0;

	(void)array;
	/*size = sizeof(array) / sizeof(array[0]);*/
	return (size);
}

/**
 * swap - swaps two elements of an array
 * @array: the array
 * @pos1: the first index (element to swap)
 * @pos2: the second index (element to swap)
 * Return: Nothing
 */
void swap(int *array, int pos1, int pos2)
{
	int temp;

	/* dont swap the same element */
	if (pos1 == pos2)
		return;
	temp = array[pos1];
	array[pos1] = array[pos2];
	array[pos2] = temp;
	printf("swapped\n");
}

/**
 * lomuto_partion - partions an array using Lomuto's scheme
 * Description: typically takes the last element, array[upperbound]
 * to be the pivot element. Places the pivot element at its
 * sorted (correct) position. The pivot is therefore left
 * out of the subarrays that result (in re-partioning)
 * @array: the array to partion
 * @lowerbound: the first index in (sub)array
 * @upperbound: the last index in (sub)array
 * @size: size of array
 * Return: the pivot's index after partion
 */
int lomuto_partition(int *array, int lowerbound, int upperbound, size_t size)
{
	int curr, j = lowerbound, pivot = array[upperbound];

	for (curr = j - 1; j < upperbound; j++)
	{
		/* check if array[j] <= pivot (an inversion), swap if true */
		if (array[j] <= pivot)
		{ /* increment curr, swap array[curr] with array[j] */
			curr++;
			swap(array, curr, j);
			/* print array after swap */
			print_array(array, size);
		}
	}
	/* correctly position pivot: swap curr & upperbound elems */
	swap(array, curr + 1, upperbound);
	print_array(array, size);
	return (curr + 1);
}
