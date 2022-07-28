#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _realloc - reallocates memory using malloc and free
 * @ptr: memory block to be reallocated
 * @old_size: size of ptr
 * @new_size: size of reallocated memory block
 * Return: pointer to reallocated block or NULL
 * if malloc fails or if new_size is 0
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	char *tmp, *p;

	if (new_size <= 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		ptr = malloc(new_size);
		return (ptr);
	}
	else if (new_size == old_size)
		return (ptr);
	if (new_size < old_size)
	{
		tmp = ptr;
		free((tmp + (old_size - new_size)));
		return (ptr);
	}
	else if (new_size > old_size)
	{
		p = ptr;
		tmp = malloc(old_size);
		if (tmp == NULL)
		{
			return (NULL);
		}
		for (i = 0; i < old_size; i++)
			*(tmp + i) = *(p + i);
		free(ptr);
		ptr = malloc(new_size);
		if (ptr == NULL)
			return (NULL);
		for (i = 0; i < old_size; i++)
			*(p + i) = *(tmp + i);
		free(tmp);
	}
	return (ptr);
}



