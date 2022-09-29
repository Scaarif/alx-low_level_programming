#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a node at idx to a linked list
 * @h: pointer to the head of list
 * @idx: the nth index(starting at 0) at which to insert the node
 * @n: value (data) of the new node
 * Return: pointer to the new(inserted) node
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int len = 0;
	dlistint_t *curr;
	dlistint_t *new;

	if (idx == 0)/* insert node at the beginning */
		add_dnodeint(h, (const int)n);
	/* get the node position if existent while getting len */
	for (curr = *h; curr->next != NULL; curr = curr->next, len++)
	{
		if (len == idx)
			break;/*insert node at curr's position*/
	}
	if (curr->next != NULL)/* we didn't get to the tail - break executed */
	{
		new = malloc(sizeof(dlistint_t));
		if (new == NULL)
			return (NULL);
		new->n = n;
		new->next = curr;
		new->prev = curr->prev;
		curr->prev->next = new;
		curr->prev = new;
		return (new);
	}
	else if (curr->next == NULL && idx == (len - 1))/*tail*/
		add_dnodeint_end(h, (const int)n);/*insert node to tail*/
	/*else, idx is greater than len (or negative) - can't insert node */
	return (NULL);
}

