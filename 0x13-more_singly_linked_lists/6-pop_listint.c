#include "lists.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * pop_listint - deletes the head of a listint list
 * Description: returns the head node's data (n)
 * @head: double pointer to the list
 * Return: integer n (of head)
 */
int pop_listint(listint_t **head)
{
	listint_t *current;
	int n;

	if (*head == NULL)/*for an empty list*/
		return (0);
	current = (*head)->next; /*the entry point/ head*/
	n = (*head)->n;
	free(*head);/*free previous head*/
	*head = current;/*point to new head*/
	return (n);
}
