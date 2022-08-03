#include "function_pointers.h"
#include <stddef.h>

/**
 * array_iterator - executes a function passed to it as a parameter
 * on each element of an array argument
 * @array: an array argument
 * @action: pointer to the function to execute
 * @size: the size of the array
 * Return: Nothing
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	int i = 0;

	/*calls back the fn passed to it with array[i] as arg*/
	for (; i < (int)size; i++)
		action(array[i]);
}

