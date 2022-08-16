#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * free_listint - frees a list
 * @head: pointer to the list
 * Return: Nothing
 */
void free_listint(listint_t *head)
{
	listint_t *current;

	while (head != NULL)
	{
		current = head; /*the entry point/ head*/
		head = head->next; /*update head 4 freeing it*/
		free(current);
	}
}
