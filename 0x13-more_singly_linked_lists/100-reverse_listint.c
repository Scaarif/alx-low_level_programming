#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/**
 * reverse_listint - reverses a linked list
 * @head: double pointer to the list
 * Return: pointer to the list
 */
listint_t *reverse_listint(listint_t **head)
{
	/*listint_t *current;*/
	listint_t *after;
	listint_t *prev;

	if (*head == NULL)
		return (*head);
	prev = NULL;
	/*current = *head;*/
	while ((*head) != NULL)
	{
		after = (*head)->next;
		/*printf("after: %d & ", after->n);*/
		(*head)->next = prev;
		prev = (*head);
		/*printf("prev: %d\n", prev->n);*/
		(*head) = after;
	}
	*head = prev;
	return (*head);
}
