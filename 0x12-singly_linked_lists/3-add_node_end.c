#include "lists.h"
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

/**
 * _strdup1 - function pointing to new copied memory allocation
 * @str: string to be copied
 * Return: pointer to new memory location, Null otherwise
 **/
char *_strdup1(char *str)
{
	char *cpy;
	int len = 0;
	int i;

	if (str == NULL)
		return (NULL);
	while (str[len])
		len++;
	cpy = malloc(sizeof(char) * (++len));
	if (cpy == NULL)
		return (NULL);
	for (i = 0; i < len - 1; i++)
		cpy[i] = str[i];
	return (cpy);
}
/**
 * _memcpy - copies information between void pointers.
 * @newptr: destination pointer.
 * @ptr: source pointer.
 * @size: size of the new pointer.
 * Return: Nothing
 */
void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
	char *char_ptr = (char *)ptr;
	char *char_newptr = (char *)newptr;
	unsigned int i;

	for (i = 0; i < size; i++)
		char_newptr[i] = char_ptr[i];
}

/**
 * _strdup - duplicates a str in the heap memory.
 * @s: Type char pointer str
 * Return: duplicated str
 */
char *_strdup(const char *s)
{
	char *new;
	size_t len;

	len = strlen(s);
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	_memcpy(new, s, len + 1);
	return (new);
}

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
	new->str = _strdup((char *)str);
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

