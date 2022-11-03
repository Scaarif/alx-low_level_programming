#include <stdio.h>

int smallest(int *arr, int pos, int size)
{
	int i, min = arr[pos], min_pos = pos;

	for (i = pos + 1; i < size; i++)
	{
		if (min > arr[i])
		{
			min = arr[i];
			min_pos = i;
		}
	}
	/*printf("min: %d at [%d]\n", min, min_pos);*/
	return min_pos;
}

void selection_sort(int arr[], int size)
{
	int i, j, min_pos, temp;


	for (i = 0; i < size; i++)
	{
		min_pos = smallest(arr, i, size);
		/* swap if necessary */
		if (min_pos > i)
		{
			temp = arr[i];
			arr[i] = arr[min_pos];
			arr[min_pos] = temp;
			/* print the array after swapping */
		}
	}
}

int main(void)
{
	int size = 10, arr[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7}, i;

	/* print original array */
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
	/* selection sort the array */
	selection_sort(arr, size);
	/* print sorted array */
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return (0);
}
