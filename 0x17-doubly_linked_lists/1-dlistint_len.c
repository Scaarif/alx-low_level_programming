#include "lists.h"

/**
 * dlistint_len - returns the number of elements in a linked list
 * @h: pointer to the head of list
 * Return: number of elements in list
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t len = 0;
	const dlistint_t *curr;

	for (curr = h; curr != NULL; curr = curr->next, len++)
		;
	return (len);
}

