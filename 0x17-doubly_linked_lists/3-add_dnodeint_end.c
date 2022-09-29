#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a list
 * @head: double pointer to the head of list
 * @n: new node's integer value
 * Return: address of the new element or NULL
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new;
	dlistint_t *tail;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	/*adding to the end; check if head is NULL*/
	if (*head == NULL)
	{
		new->next = *head; /*list initially empty*/
		new->prev = NULL;
		*head = new;
	}
	else
	{
		/*traverse the list to last node*/
		for (tail = *head; tail->next != NULL; tail = tail->next)
			;
		tail->next = new;
		new->prev = tail;
		new->next = NULL;
	}

	return (new);/*points to new node*/
}
