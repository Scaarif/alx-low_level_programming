#include "lists.h"
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

/**
 * add_node - adds a new node at the beginning of list_t list
 * @head: a pointer to the pointer to the head
 * @str: the new node's string
 * Return: pointer to the new node
 */
list_t *add_node(list_t **head, const char *str)
{
	size_t len = 0;
	list_t *new;

	new = malloc(sizeof(list_t));
	
	if (new == NULL)
	{
		free(new);
		return (NULL);
	}
	new->str = strdup(str);
	for (; str[len] != '\0'; len++)
		;
	new->len = len;
	new->next = *head;
	*head = new;
	return (*head);/*same as return(new)*/
}

