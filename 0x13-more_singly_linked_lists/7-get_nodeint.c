#include "lists.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * get_nodeint_at_index - returns node at nodeindex of a list
 * @head: pointer to the list
 * @index: node index
 * Return: node at index
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *node;
	unsigned int n = 0;

	if (head != NULL)/*for an empty list*/
	{
		node = head; /*the entry point/ head*/
		for (; node != NULL && n <= index; node = node->next, n++)
		{
			if (n == index)
				return (node);
		}
	}
	return (NULL);
}
