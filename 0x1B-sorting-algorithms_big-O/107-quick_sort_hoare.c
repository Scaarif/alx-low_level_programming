#include "sort.h"


/**
 * actual_quick_sort - actually sorts the array
 * @array: the array to sort
 * @left: start index
 * @right: last(stop) index
 * @pivot: the basis of comparison/ partition
 * @size: size of array
 * Return: Nothing
 */
void actual_quick_sort(int *array, int left, int right, size_t size)
{
	int loc;

	/* base case, array size == 0 or 1 (sorted) */
	if (left >= right)
		return; /* done with sorting */
	/* sort part of the array as partitioned */
	loc = hoare_partition(array, left, right, size);
	/*printf("loc: [%d] -> %d\n", loc, array[loc]);*/
	/* sort the left part of array: 0 - pivot/loc */
	actual_quick_sort(array, left, loc, size);
	/* sort the second partition: loc + 1, right */
	actual_quick_sort(array, loc + 1, right, size);
}

/**
 * quick_sort_hoare - sorts an array in ascending order using
 * Hoare's partition scheme'd QuickSort.
 * @array: the array to sort
 * @size: is the size of the array (number of elements)
 * Return: Nothing
 */
void quick_sort_hoare(int *array, size_t size)
{
	int left = 0, right = (int)size - 1;

	/* sort */
	actual_quick_sort(array, left, right, size);
}
