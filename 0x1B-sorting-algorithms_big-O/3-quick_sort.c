#include "sort.h"

/**
 * partition - partions an array (or subarray) into two subarrays
 * partioned by a pivot (all elements less than the pivot in one
 * subarray and those larger thn in the other
 * @left: the element at the 0th index of a (sub)array
 * @right: the element at the (n - 1)th index of the 9sub)array
 * @pivot: the element around which the partitioning is based
 * @size: size of array
 * Return: final position of the pivot (i.e. the index)
 */
int partition(int *array, int left, int right, int pivot, size_t size)
{
	int partitioned = 0, temp;

	/* start at pivot = left */
	while (!partitioned)
	{
		/* compare [pivot] with [right]: as long as [pivot] <= [right] && pivot != right, advance right (right --)*/
		while (pivot != right && array[pivot] <= array[right])
			right--;
		/* if [pivot] > [right], swap them and set pivot to right */
		if (pivot == right)
			partitioned = 1;
		else if (array[pivot] > array[right])
		{
			temp = array[pivot];
			array[pivot] = array[right];
			array[right] = temp;
			pivot = right;
		}
		/* as long as [left] < [pivot] && left != pivot && !partitioned, advance left (left++) */
		while (!partitioned && pivot != left && array[left] <= array[pivot])
			left++;
		if (pivot == left)
			partitioned = 1;
		/* if [left] > [pivot], swap the values and set pivot to left */
		else if (array[left] > array[pivot])
		{
			temp = array[left];
			array[left] = array[pivot];
			array[pivot] = temp;
			pivot = left;
		}
		/* repeat comparison (between [pivot] and [right]) - like we started */
	}
	/* return when pivot == left or pivot == right (pivot) - array partitioned */
	/*printf("end with pivot at: [%d] -> %d\n", pivot, array[pivot]);*/
	print_array(array, size);
	return (pivot);
}

/**
 * actual_quick_sort - actually sorts the array
 * @array: the array to sort
 * @left: start index
 * @right: last(stop) index
 * @pivot: the basis of comparison/ partition
 * @size: size of array
 * Return: Nothing
 */
void actual_quick_sort(int *array, int left, int right, int pivot, size_t size)
{
	int loc;

	/* base case, array size == 0 or 1 (sorted) */
	if (left >= right)
		return; /* done with sorting */
	/* sort part of the array as partitioned */
	/*loc = partition(array, left, right, pivot, size);*/
	loc = lomuto_partition(array, left, right, size);
	/* sort the first partition */
	actual_quick_sort(array, left, loc - 1, pivot, size);
	/* sort the second partition */
	actual_quick_sort(array, loc + 1, right, loc + 1, size);
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using Quick sort algorithm
 * @array: pointer to the array to be sorted
 * @size: number of elements in the array
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	int left, pivot = 0, right = ((int)size - 1);

	left = pivot;
	actual_quick_sort(array, left, right, pivot, size);
}
