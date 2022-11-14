#include <stdio.h>
#include <stdlib.h>

/* Array printing function */
void printArray(int *arr, int size)
{
	int i;

	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

/* This function allows you to swap two components. */
void swap(int *arr, int i, int j, int size)
{
	int temp;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
	printf("swapped\n");
	printArray(arr, size);
}

/* This function uses the last element as the pivot, and moves all smaller items to the left of pi
inserts pivot in the appropriate location in the sorted array. */

int partition(int *arr, int start, int end, int size)
{
	int pivot, i, j;

	/* pivot*/
	pivot = arr[end];

	/* Index of a smaller element that specifies the pivot's correct position so far. */
	i = (start - 1);

	for (j = start; j <= end - 1; j++)
	{
		/* If current element is smaller than the pivot */
		if (arr[j] < pivot)
		{
			i++;
			swap(arr, i, j, size);
		}
	}
	swap(arr, i + 1, end, size);
	return (i + 1);
}

void quickSort(int *arr, int start, int end, int size)
{
	int pi;

	if (start < end)
	{
	
		/* The partitioning index is represented by pi. */
		
		pi = partition(arr, start, end, size);
		
		/* Separately sort elements before
		partition and after partition */
		quickSort(arr, start, pi - 1, size);
		quickSort(arr, pi + 1, end, size);
	}
}

int main(void)
{
	int arr[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	size_t n = sizeof(arr) / sizeof(arr[0]);

	printf("Original array: ");
	printArray(arr, (int)n);
	quickSort(arr, 0, (int)n - 1, (int)n);
	printf("Sorted array: ");
	printArray(arr, (int)n);
}
