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
	int inner, outer, toInsert, interval = 1, elems = MAX, i = 0;

	/* Knuth series to calculate interval/gap */
	while (interval <= elems / 3)
		interval = interval * 3 + 1;
	/* actual shell sorting */
	printf("start interval: %d\n", interval);
	while (interval > 0)
	{
		printf("iteration %d#:", i);
		display(array);
		/* start sorting the columns (items in i + interval) */
		/* outer is the outer loop's (iterator); (interval++ -> n - 1) */
		for (outer = interval; outer < elems; outer++)
		{
			toInsert = array[outer];
			inner = outer;
			/*printf("inner: %d\n", inner);*/
			/*printf("outer: %d\n", outer);*/
			/**
			 * starting @ inner = outer; -> i = outer; j = i;
			 * while inner > interval - 1 && [inner - interval] >= temp ([outer])
			 * i.e. since to get the row above the [inner]/[outer] row in a column [outer]
			 * we have to subtract interval from it: [inner] is the bottom most row in col
			 * we can only get it (i.e. row above exits only) if; inner >= interval &
			 * only swap if [inner - interval] > temp (toInsert) i.e.
			 * swap if the row above has a value > that row (below it)
			 */
			while (inner >= interval && array[inner - interval] > toInsert)
			{
				/**
				 * this loop swaps the rows in a column, if necessary
				 * (starting from the last row and upwards to the first)
				 * the last row's value is temp (toInsert) & is compared with every other
				 * row (above it) in the column, and that row's value changed if necessary
				 * the loop sets up to 2nd row in the column, the first is finally set after
				 * loop exits
				*/
				array[inner] = array[inner - interval];
				inner -= interval;
				/*printf(" item moved :%d\n", array[inner]);*/
				/*printf("(inner loop) inner: %d\n", inner);*/
				printf("array after move: ");
				display(array);
			}
			/**
			 * now set the value at [inner] i.e. the top/first row of a col
			 * regardless (of swap or not)
			 */
			array[inner] = toInsert;
			/*printf(" item inserted: %d, at position: %d\n", toInsert, inner);*/
			printf("array after temp insert: ");
			display(array);
		}
		/* adjust interval (decrement it) - lengthen the column */
		interval = (interval - 1) / 3;
		printf("interval after iteration %d#: %d\n", i, interval);
		i++;  /* increment iterations */
	}
}

/**
 * main - check code
 * Return: 0 always
 */
int main(void)
{
	int array[MAX] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	/*int array[MAX] =  {4, 6, 3, 2, 1, 9, 7};*/

	printf("original array: ");
	display(array);
	printline(50);
	shellSort(array);
	printf("sorted array: ");
	display(array);
	printline(50);
	return (0);
}
