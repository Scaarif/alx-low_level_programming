#include "sort.h"

/**
 * printline - prints a '=' line
 * @count: the number of '=' to print
 * Return: Nothing
 */
void printline(int count)
{
	int i;

	for (i = 0; i < count; i++)
		printf("=");
	printf("\n");
}

/**
 * display - prints out the array
 * @array: the array to print out
 * @size: the array to print out
 * Return: Nothing
 */
void display(int *array, size_t size)
{
	int i = 0;

	printf("[");
	for (; i < (int)size; i++)
		printf("%d ", array[i]);
	printf("]\n");
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
}

/**
 * get_interval - returns the correct knuth series value
 * @interval: the current value
 * @size: the number of elements in a list/array
 * Return: the calculated interval
 */
int get_interval(int interval, size_t size)
{
	while (interval <= (int)size / 3)
	{
		interval = interval * 3 + 1;
		printf("calc_interval: %d", interval);
	}
	return interval;
} 

/**
 * shell_sort - sorts an array in ascending order
 * @array: the array to sort
 * @size: the number of elements in array
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	int interval, i;

	interval = 1;
	/* get knuth series value -> interval */
	interval = get_interval(interval, size);
	/* while interval > 1 */
	while (interval > 0)
	{
		/* in (size - interval) passes, do ...*/
		printf("interval: %d\n", interval);
		for (i = 0; i < ((int)size - interval); i++)
		{
			/* compare array[i] & array[i + interval]: swap if out of order */
			if (array[i] > array[i + interval])
			{
				swap(array, i, (i + interval));
				printf("swapped: (%d at [%d] & %d at [%d])\n", array[i+interval], i + interval, array[i], i );
				display(array, size);
			}
		}
		/*update interval */
		interval = (interval - 1) / 3;
	}	
}
