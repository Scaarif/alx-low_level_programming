#include "lists.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * add_nodeint_end - adds a node to the end of a list
 * @head: double pointer to the list
 * @n: integer to be added to the ew node
 * Return: pointer to the list
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new;
	listint_t *end;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	end = *head;/*get last node*/
	if (end == NULL)/*for an empty list*/
	{
		new->next = NULL;
		*head = new;
	}
	else
	{
		for (; end->next != NULL; end = end->next)
			;
		end->next = new;
		new->next = NULL;
	}
	return (*head);
}
