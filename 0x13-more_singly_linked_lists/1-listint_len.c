#include "lists.h"
#include <stdio.h>
#include <stddef.h>

/**
 * listint_len - returns the nuber of elements in a list
 * @h: pointer to the list
 * Return: number of nodes in list
 */
size_t listint_len(const listint_t *h)
{
	size_t len = 0;
	const listint_t *current;

	current = h; /*the entry point/ head*/
	for (; current != NULL; current = current->next, len++)
		;
	return (len);
}
