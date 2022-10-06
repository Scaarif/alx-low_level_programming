#include "monty.h"

/**
 * free_stack - frees a doubly linked list
 * Return: Nothing
 */
void free_stack(void)
{
	stack_t *curr;

	while (stack != NULL)
	{
		curr = stack;
		stack = stack->next;
		free(curr);
	}
}

