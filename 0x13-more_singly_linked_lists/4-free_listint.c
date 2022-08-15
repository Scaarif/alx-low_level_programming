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

	current = head; /*the entry point/ head*/
	for (; current != NULL; current = current->next)
		free(current);
}
