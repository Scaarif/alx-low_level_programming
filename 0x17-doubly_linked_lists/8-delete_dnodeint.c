#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the nth node of a linked list
 * @head: double pointer to the head of list
 * @index: the nth index(starting at 0)
 * Return: 1 if success and -1 otherwise
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int len = 0;
	dlistint_t *curr;
	/*dlistint_t *toFree;*/

	/* get to node if existent while getting len & delete */
	if (*head == NULL)
		return (-1);
	for (curr = *head; curr != NULL; curr = curr->next, len++)
	{
		if (len == index)
		{
			/*toFree = curr;*/
			if (curr != *head)
				curr->prev->next = curr->next;
			if (curr->next != NULL)
				curr->next->prev = curr->prev;
			if (curr == *head)
				*head = curr->next;
			free(curr);
			return (1);
		}
	}
	/*node doesn't exist: head's either NULL or index too high*/
	return (-1);

}

