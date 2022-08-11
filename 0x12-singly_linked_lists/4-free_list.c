#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * free_list - frees a list_t list
 * @head: a pointer to a list_t list
 * Return: Nothing
 */
void free_list(list_t *head)
{
	list_t *current;

	if (head != NULL)
	{
		current = head;
		for (; current != NULL; current = current->next)
		{
			free(current->str);
			free(current);/*unless i also need to free current->str*/
		}
	}

}

