#include "lists.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * sum_listint - returns sum of all data(n) of a list
 * @head: pointer to the list
 * Return: integer sum
 */
int sum_listint(listint_t *head)
{
	listint_t *node;
	int sum = 0;

	if (head != NULL)/*for an empty list*/
	{
		node = head; /*the entry point / head*/
		for (; node != NULL; node = node->next)
			sum += node->n;
	}
	return (sum);
}

