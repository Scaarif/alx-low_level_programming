#include "lists.h"
#include <stdio.h>
#include <stddef.h>

/**
 * print_list - prints all the elements of a list_t list
 * @h: a pointer to a list_t list
 * Description: prints [0] (nil) if str is NULL
 * Return: size_t number of nodes in list
 */
size_t print_list(const list_t *h)
{
	size_t len = 0;
	const list_t *current;

	for (current = h; current != NULL; len++, current = current->next)
	{
		if (current->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%d] %s\n", current->len, current->str);
	}
	return (len);
}

