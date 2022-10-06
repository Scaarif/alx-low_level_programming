#include "monty.h"

/**
 * queue - does nothing to the top of the stack
 * @head: double pointer to head(top) of stack
 * @n: line number
 * Return: Nothing
 */
void queue(stack_t **head, unsigned int n)
{
	(void)n;
	(void)head;
}

/**
 * stack_ - does nothing to the top of the stack
 * @head: double pointer to head(top) of stack
 * @n: line number
 * Return: Nothing
 */
void stack_(stack_t **head, unsigned int n)
{
	(void)n;
	(void)head;
}

/**
 * queue_push - (an opcode) pushes an element to the stack's rear(tail)
 * @head: double pointer to head of stack
 * @n: integer argument
 * Description: adds new element to the head of list
 * Return: Nothing
 */
void queue_push(stack_t **head, unsigned int n)
{
	stack_t *new, *tail = *head;

	/*checking if n - done outside this fn */
	/*printf("in push\n");*/
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
    new->n = (int)n;
    new->next = NULL;
    /* navigate to the tail of the stack */
    if (tail != NULL)
    {
        while (tail->next != NULL)
            tail = tail->next;
        new->prev = tail;
        tail->next = new;
    }
    else
    {
        new->prev = NULL;
        *head = new;
    }
}
