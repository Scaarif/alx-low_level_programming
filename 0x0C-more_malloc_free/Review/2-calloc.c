#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _calloc - allocates memory for an array using malloc
 * @nmemb: number of elements in array
 * @size: zise of the elements type
 *Description: initializes elements to zero
 * Return: pointer to allocated memory or NULL
 * if nmemb or size is 0 or if malloc fails
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	int *ptr;
	/*char *p;*/
	unsigned int i;

	if (nmemb <= 0 || size <= 0)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
	{
		free(ptr);
		return (NULL);
	}
	/* Initialize the elements to zero */
	/*p = ptr;*/ /*p points to same addresses as ptr*/
	/*this assignment essentially changes values in ptr*/
	for (i = 0; i < nmemb; i++)
		ptr[i] = 0;
	return (ptr);
}


