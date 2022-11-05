#include <stdio.h>
#include <stdbool.h>

#define MAX 10

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
 * Return: Nothing
 */
void display(int *array)
{
	int i = 0;

	printf("[");
	for (; i < MAX; i++)
		printf("%d ", array[i]);
	printf("]\n");
}
/**
 * shellSort - sorts an array in ascending order using shell sort
 * @array: the array to sort
 * Return: Nothing
 */
void shellSort(int *array)
{
	int i, j = 0, interval = MAX, n = MAX, flag = 1, temp;

	/* Knuth series to calculate interval/gap */
	/* actual shell sorting */
	printf("start interval: %d\n", interval);
	while (flag == 1 || interval > 1)
	{
		printf("iteration %d#:", j);
		display(array);
		flag = 0;
		interval = (interval + 1) / 2;
		printf("interval: %d\n", interval);
		/* start sorting the columns (items in i + interval) */
		for (i = 0; i < (n - interval); i++)
		{
			printf("comparing: (%d at [%d] & %d at [%d])\n", array[i+interval], i + interval, array[i], i );
			if (array[i + interval] < array[i])
			{
				temp = array[i + interval];
				array[i + interval] = array[i];
				array[i] = temp;
				flag = 0;
			}
		}
		j++;
	}
}

/**
 * main - check code
 * Return: 0 always
 */
int main(void)
{
	int array[MAX] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};

	printf("original array: ");
	display(array);
	printline(50);
	shellSort(array);
	printf("sorted array: ");
	display(array);
	printline(50);
	return (0);
}
