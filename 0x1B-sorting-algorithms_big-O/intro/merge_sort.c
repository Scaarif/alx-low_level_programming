#include "sort.h"

/**
 * print_sub_arrays - prints the parts of the array currently
 * being worked on
 * @array: the original array
 * @start: the start index
 * @mid: the mid index
 * @end: the end index (inclusive)
 */
void print_sub_arrays(int *array, int start, int mid, int end)
{
	int k, j = mid + 1;

	printf("Merging...\n");
	printf("[left]: ");
	for (k = start; k <= mid; k++)
		printf("%d ", array[k]);
	printf("\n");
	printf("[right]: ");
	for (k = j; k <= end; k++)
		printf("%d ", array[k]);
	printf("\n");
}

/**
 * copy_merged - copies the merged sub_arrays into the original
 * Also prints the sorted (& merged) sub-array, temp
 * @array: the original
 * @temp: the  sorted array of merged sub-arrays
 * @start: the beginning of first (left) sub-array
 * @index: the last index in temp (inclusive)
 */
void copy_merged(int *array, int *temp, int start, int index)
{
	int k;

	printf("[Done]: ");
	for (k = start; k < index; k++)
	{
		array[k] = temp[k];
		if (k < index - 1)
			printf("%d, ", array[k]);
		else
			printf("%d", array[k]); /* last element */
	}
	printf("\n");
}

/**
 * merge - merges two sorted sub-arrays
 * @array: holds the sorted elements
 * @start: 0th index
 * @mid: the middle index
 * @end: last index in array
 * @size: size of original array
 * Return: Nothing
 */
void merge(int *array, int start, int mid, int end, int size)
{
	int i = start, j = mid + 1, index = start, *temp;

	/* allocate memory to temp; size = size */
	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return; /* malloc failure */
	print_sub_arrays(array, start, mid, end);
	while (i <= mid && j <= end)
	{
		if (array[i] < array[j])
		{
			temp[index] = array[i];
			i++;
		}
		else
		{
			temp[index] = array[j];
			j++;
		}
		index++;
	} /* merge the rest of the elements (from a single sub-array) */
	if (i > mid) /* all left sub-array elements merged  */
	{
		while (j <= end)
		{
			temp[index] = array[j];
			index++;
			j++;
		}
	}
	else /* all right sub-array elements merged */
	{
		while (i <= mid)
		{
			temp[index] = array[i];
			index++;
			i++;
		}
	} /* copy into array, temp & print temp */
	copy_merged(array, temp, start, index);
}

/**
 * actual_merge_sort - does the actual merge sorting
 * @array: the array to be sorted
 * @start: the 0th index of (sub)array
 * @end: the last (exclusive) index of the (sub)array
 * @size: size of original array
 * Return: Nothing
 */
void actual_merge_sort(int *array, int start, int end, int size)
{
	int mid;

	/* check that array isn't yet sorted (base case untrue ) */
	if (start < end) /* NOT 0 or 1 elements: automatically sorted */
	{
		mid = (start + end) / 2; /* divide array */
		actual_merge_sort(array, start, mid, size); /* conquer left sub-array */
		actual_merge_sort(array, mid + 1, end, size);
		/* merge sorted sub-arrays */
		merge(array, start, mid, end, size);
	}
}

/**
 * merge_sort - sorts elements aof an array using Merge Sort algorithm
 * Description:
 * @array: the array to sort
 * @size: number of elements in the array
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
	int start = 0, end = (int)size - 1;

	/* call actual_merge_sort */
	actual_merge_sort(array, start, end, (int)size);
}
