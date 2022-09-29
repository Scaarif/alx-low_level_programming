#include "lists.h"

/**
 * print_dlistint - prints all the elements of a dlistint_t list
 * @h: pointer to the head of list
 * Return: number of elements in list
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t len = 0;
	const dlistint_t *curr;

	for (curr = h; curr != NULL; curr = curr->next, len++)
		printf("%d\n", curr->n);
	return (len);
}

