#include "sort.h"

/**
 * hoare_partion - partions an array using Hoare's scheme
 * Description: typically takes the first element, array[lowerbound]
 * to be the pivot element. Does NOT place the pivot element at its
 * sorted (correct) position. The pivot is therefore included in
 * first subarray (of the 2 resulting) in re-partioning
 * Required: pivot should always be the last element...
 * @array: the array to partion
 * @lowerbound: the first index in (sub)array
 * @upperbound: the last index in (sub)array
 * @size: number of elements in array
 * Return: the pivot's index after partion, which's end position
 */
int hoare_partition(int *array, int lowerbound, int upperbound, size_t size)
{
	int start = lowerbound - 1, end = upperbound + 1, pivot;

	pivot = array[upperbound];
	/*printf("pivot: [%d] -> %d\n", upperbound, pivot);*/
	while (1) /* infinitely loop */
	{
	/* advance start towards end */
		do
			start++;
		while (array[start] < pivot);
	/* advance end towords start */
		do
			end--;
		while (array[end] > pivot);
	/* if a cross (start >= end), return end */
		if (start >= end)
		{
			/*printf("end: [%d] -> %d & start: [%d] -> [%d]\n", end, array[end], start, array[start]);*/
			return (end);
		}
	/* if inversion, swap the elements at start & end */
		/* solve inversion & continue */
		printf("start: [%d] -> [%d] for pivot: %d\n", start, array[start], pivot);
		printf("end: [%d] -> [%d]\n", end, array[end]);
		swap(array, start, end);
		/* print array after each swap */
		print_array(array, size);
	}
}
