#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 10

/**
 * insertion_sort - insertion sorts an array
 * @arr: the array to sort
 * @n: the size of the array
 * Return: Nothing
 */
void insertion_sort(int arr[], int n)
{
	int i, j, temp;

	for (i = 1; i < n; i++)
	{
		temp = arr[i];
		j = i - 1;
		while (temp < arr[j]  && j >= 0)
		{
			/* move the element forward by 1(to arr[i]) */
			arr[j+1] = arr[j];
			j--;
		}
		/* insert arr[i] element to correct position in sorted set */
		arr[j+1] = temp;
	}
}

int main(void)
{
	/* size of array = sizeof(array) / sizeof(array[0])*/
	int i, arr[SIZE] =  {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};

	printf("Unsorted array:");
	for (i = 0; i < SIZE; i++)
		printf("%d ", arr[i]);
	printf("\n");
	/* sort the array */
	insertion_sort(arr, SIZE);
	printf("\nThe sorted array is: ");
	for (i = 0; i < SIZE; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return (0);
}
