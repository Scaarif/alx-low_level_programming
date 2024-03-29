#include "sort.h"

/**
 * shell_sort - sorts an array in ascending order using shell sort
 * Description: shell sort is an improvement of insertion sort.
 * Reduces the number of swaps by increasing the interval an element can move
 * to its rightful position (in insertion sort, an element moves a step a time)
 * @array: the array to sort
 * @size: the number of elements in the array
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	int interval = 1, temp, col, col_row;

	/* calculate a knuth series interval: initialized to one at start */
	while (interval <= (int)size / 3)
		interval = interval * 3 + 1;
	/* while interval is greater than 0 (interval > 0) */
	while (interval > 0)
	{
	/* iterate over a column (elements at the same interval from each other) */
		for (col = interval; col < (int)size; col++)
		{
	/* for a column; get last row element, [farthest index], save it in temp */
			temp = array[col];
			col_row = col; /* last row in a column */
	/* while in column: (col_row >= interval && [col_row - interval] > temp */
			while (col_row >= interval && array[col_row - interval] > temp)
			{
	/* update col_row's value -> to [col_row - interval]'s i.e. to value just above it */
				array[col_row] = array[col_row - interval]; /* move that value down the column */
	/* adjust col_row to the row above it & repeat if True (a row exits and value needs swapping) */
				col_row -= interval; /* move up the column rows & repeat if True */
			}
	/* Regardless, (out of loop) adjust/update top col_row's value to temp */
			array[col_row] = temp; /* this' the col's topmost row */
		}
	/* update interval (decrement it) & repeat while True */
		interval = (interval - 1) / 3;
		/* print array every time interval changes */
		print_array(array, size);
	}
}
