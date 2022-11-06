#include "sort.h"

/**
 * cocktail_sort - sorts an array (in ascending order) using cocktail shaker sort
 * Description: is an improvement of bubble sort -> uses bidirectional movement
 * fasten the moving of items to the beginning of the array: bubble sort only moves
 * items in one direction
 * @array: the array to sort
 * @size: number of elements in the array
 */
void cocktail_sort(int *array, size_t size)
{
	int start, end, left, right, i;

	/* start and end mark the first and last index to check */
	left = 0;
	right = (int)size - 1;
	while (left <= right)
	{
		start = right;
		end = left;
		/* advance & swap forward */
		for (i = left; i < right; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(array, i, i + 1);
				printf("forward: ");
				display(array, size);
				end = i;
			}
		}
		/* decrease right since the elemnts after end are in correct order */
		right = end;
		printf("right: %d\n", right);
		printf("start backwards trace with left at: %d\n", left);
		/* advance  & swap backwards */
		for (i = right; i > left; i--)
		{
			if (array[i - 1] > array[i])
			{
				swap(array, i - 1, i);
				printf("backward: ");
				display(array, size);
				start = i;
			}
		}
		/* increase left since the element before start are sorted */
		left = start;
		printf("left: %d\n", left);
	}
}
