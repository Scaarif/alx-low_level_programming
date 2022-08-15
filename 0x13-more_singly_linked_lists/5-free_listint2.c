#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * free_listint2 - frees a list
 * @head: pointer to the list
 * Description: sets head to NULL
 * Return: Nothing
 */
void free_listint2(listint_t **head)
{
	listint_t *current;

	current = *head; /*the entry point/ head*/
	for (; current != NULL; current = current->next)
		free(current);
	*head = current; /*set head to NULL*/
}
