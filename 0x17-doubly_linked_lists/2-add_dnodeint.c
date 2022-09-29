#include "lists.h"

/**
 * add_dnodeint - adds a new node at the beginning of a list
 * @head: double pointer to the head of list
 * @n: new node's integer value
 * Return: address of the new element or NULL
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	/*adding to the beggining; check if head is NULL*/
	if (*head != NULL)
		(*head)->prev = new; /*list initially non-empty*/
	new->next = *head;
	new->prev = NULL;
	*head = new;
	return (*head);/*points to new node*/
}
