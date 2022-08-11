#include "lists.h"
#include <stdio.h>
#include <stddef.h>

/**
 * list_len - counts the elements of a list_t list
 * @h: a pointer to a list_t list
 * Return: size_t number of nodes in list
 */
size_t list_len(const list_t *h)
{
	size_t len = 0;
	const list_t *current;

	for (current = h; current != NULL; len++, current = current->next)
		;
	return (len);
}

