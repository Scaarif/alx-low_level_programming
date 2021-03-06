#include "main.h"
#include <stdlib.h>
#include <stddef.h>
/**
 * create_array - creates an array of chars
 * Description: initializes the array with a specific char
 * @size: size of array
 * @c: char to initialize the array with
 * Return: pointer to the array
 */

char *create_array(unsigned int size, char c)
{
	unsigned int i = 0;
	char *a;

	if (size == 0)
		return (NULL);
	a = malloc(sizeof(char) * size);
	if (a == NULL)
		return (NULL);
	for (; i < size; i++)
		*(a + i) = c;
	return (a);
}


