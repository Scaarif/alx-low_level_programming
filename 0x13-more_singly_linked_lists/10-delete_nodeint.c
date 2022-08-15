#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/**
 * delete_nodeint_at_index - deletes node at index of a list
 * @head: double pointer to the list
 * @index: node index
 * Return: 1 on success and -1 otherwise
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *to_del;
	listint_t *prev;
	listint_t *after;
	unsigned int idx = 0;

	if (*head == NULL)
		return (-1);
	prev = *head; /*get prev*/
	if (index == 0)
	{
		to_del = *head;
		*head = to_del->next;
	}
	else
	{

		for (; prev != NULL && idx < index - 1; prev = prev->next, idx++)
			;
		/*printf("prev_idx: %d\n", idx);*/
		if (idx + 1 != index)
			return (-1); /*impossible to insert node*/
		to_del = prev->next;
		after = to_del->next;
		prev->next = after;
	}
	free(to_del);
	return (1);
}

