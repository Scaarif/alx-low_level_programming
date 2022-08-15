#include "lists.h"
#include <stdio.h>
#include <stddef.h>

/**
 * print_listint - prints all the elements of a listint_t list
 * @h: pointer to the list
 * Return: number of nodes in list
 */
size_t print_listint(const listint_t *h)
{
	size_t len = 0;
	const listint_t *current;

	current = h; /*the entry point/ head*/
	for (; current != NULL; current = current->next, len++)
		printf("%d\n", current->n);
	return (len);
}
