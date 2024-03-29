#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/**
 * insert_nodeint_at_index - inserts new node at nodeindex of a list
 * @head: double pointer to the list
 * @index: node index
 * @n: interger of inserted node
 * Return: pointer to inserted node
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int index, int n)
{
	listint_t *new;
	listint_t *prev;
	listint_t *after;
	unsigned int idx = 0;

	if (index && *head)
	{
		prev = *head; /*get prev*/
		for (; prev != NULL && idx < index - 1; prev = prev->next, idx++)
			;
		/*printf("prev_idx: %d\n", idx);*/
		if (idx + 1 != index)
			return (NULL); /*impossible to insert node*/
		after = prev->next;
	}
	else if (index == 0)
	{
		after = *head;
	}
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = after;
	if (prev)
		prev->next = new;
	if (index == 0)
		*head = new; /*update head*/
	return (new);
}

