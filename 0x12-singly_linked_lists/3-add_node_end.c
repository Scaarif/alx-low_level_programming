#include "lists.h"
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

/**
 * add_node_end - adds a new node to the end of list_t list
 * @head: a pointer to the pointer to the head
 * @str: the new node's string
 * Return: pointer to the new node
 */
list_t *add_node_end(list_t **head, const char *str)
{
	size_t len = 0;
	list_t *new;
	list_t *last;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	new->str = strdup(str);
	for (; str[len] != '\0'; len++)
		;
	new->len = len;
	if (*head == NULL)/*its an empty list*/
	{
		/*printf("in a null situation:\n");*/
		new->next = NULL;
		*head = new; /*new head*/
	}
	else
	{
		/*printf("null situation avoided\n");*/
		last = *head;
		/*printf("we have a last node!");*/
		for (; last->next != NULL; last = last->next)
			;/*loop stops at last node*/
		last->next = new;
		new->next = NULL; /*new last*/
	}
	return (new);
}

