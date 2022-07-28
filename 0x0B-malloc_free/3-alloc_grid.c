#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - creates a 2d integer grid
 * Description: Each element of the grid should be initialized to 0
 * @width: int size width of array
 * @height: int size height of array
 * Return: Pointer to new grid
 */

int **alloc_grid(int width, int height)
{
	int **grid;
	int i, j;

	if (width + height < 2 || width < 1 || height < 1)
		return (NULL);

	/*grid is a pointer to pointers (double pointer) - an array of arrays */
	/*i.e. it is a pointer to 1D arrays (sorta like single rows) in 2D arrays*/
	grid = malloc(height * sizeof(*grid));
	/*i.e. total size = size of pointer (array), (int *) * height (no of arrays/ rows) */
	if (grid == NULL)
	{
		free(grid);
		return (NULL);
	}
	for (i = 0; i < height; i++)
	{
		/*now assign memory to individual arrays/rows;*/
		grid[i] = malloc(width * sizeof(**grid));
		/* **grid is the value of array elements (type = type of element) */
		if (grid[i] == NULL)
		{
			for (i--; i >= 0; i--)
				free(grid[i]);/* free row/ array */
			free(grid);/* free 2D array */
			return (NULL);
		}
		for (j = 0; j < width; j++)
			grid[i][j] = 0;/* initialize the arrays/rows */
	}

	return (grid);
}
