#include "function_pointers.h"

/**
 * int_index - searches for an  integer
 * @array: array of ints to search from
 * @size: size of array (no of elements)
 * @cmp: pointer to a ints compare function;
 * compares an element of the array to a given int
 * Return: an int index
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i = 0;

	if (size > 0 && array != NULL && cmp != NULL)
	{
		for (; i < size; i++)
		{
			if (cmp(array[i]))/*if true*/
				return (i);
		}
		/*else: if no match for what we are looking for */
		return (-1);
	}
	/*else*/
	return (-1);
}

