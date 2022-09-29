#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a linked list
 * @head: pointer to the head of list
 * @index: the nth index(starting at 0)
 * Return: pointer to the nth node
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int len = 0;
	dlistint_t *curr;

	/* get the node if existent while getting len */
	for (curr = head; curr != NULL; curr = curr->next, len++)
	{
		if (len == index)
			return (curr);
	}
	/*else ((len - 1) < index || (len - 1) > index)*/
	return (NULL);/*node doesn't exist*/

}

