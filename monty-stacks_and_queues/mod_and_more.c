#include "monty.h"

/**
 * mod - calculates the modulus of dividing two elements of the stack
 * Description: i.e. the head->next by head
 * and stores the result in head->next, popping head
 * @head: double pointer to head(top) of stack
 * @n: line number
 * Return: Nothing
 */
void mod(stack_t **head, unsigned int n)
{
	stack_t *temp;
	(void)n;

	if (*head != NULL)
		temp = *head;
	if (temp->next)/*then we have at least two elements*/
	{
		*head = temp->next;/*i.e the 2nd element*/
		if (temp->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", n);
			exit(EXIT_FAILURE);
		}
		else
			(*head)->n = (*head)->n % temp->n;
		(*head)->prev = NULL;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
}

/**
 * pchar - prints the character stored at the top of the stack
 * Description: i.e. treats the integer as an ascii value
 * if the integer is not in the ascii table - exits with an error
 * @head: double pointer to head(top) of stack
 * @n: line number
 * Return: Nothing
 */
void pchar(stack_t **head, unsigned int n)
{
	(void)n;

	if (*head != NULL)
	{
		if ((*head)->n < 0 || (*head)->n > 127)
		{
			fprintf(stderr, "L%u: can't pchar, value out of range\n", n);
			exit(EXIT_FAILURE);
		}
		else
			printf("%c\n", (*head)->n);
	}
	else
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", n);
		exit(EXIT_FAILURE);
	}
}

/**
 * pstr - prints the string (of characters) in the stack from the top down
 * Description: i.e. treats the integers as an ascii values
 * if the integer is 0, not in the ascii table  or the stack is empty,
 * the function exits with an error
 * @head: double pointer to head(top) of stack
 * @n: line number
 * Return: Nothing
 */
void pstr(stack_t **head, unsigned int n)
{
	stack_t *curr = *head;
	(void)n;

	if (*head != NULL)
	{
		while (curr != NULL)
		{
			if (curr->n < 1 || curr->n > 127)
				break; /*stop*/
			printf("%c", curr->n);
			curr = curr->next;
		}
	}
	printf("\n");/*in the case of an empty stack & at end of string */
}

/**
 * rotl - rotates the stack to the top
 * Description: i.e. the top element of the stack becomes the last one
 * and the second top element becomes the first one (the head)
 * @head: double pointer to head(top) of stack
 * @n: line number
 * Return: Nothing
 */
void rotl(stack_t **head, unsigned int n)
{
	stack_t *temp, *last = *head;
	(void)n;

	/*need at least two elements to swap, else stack remains unchanged*/
	if (*head != NULL && (*head)->next)
	{
		temp = (*head)->next;
		/*get the last element*/
		while (last->next != NULL)
			last = last->next;
		/* do the updates */
		last->next = *head;
		(*head)->prev = last;
		(*head)->next = NULL;
		temp->prev = NULL;
		*head = temp;
	}
}

/**
 * rotr - rotates the stack to the bottom
 * Description: i.e. the last element of the stack becomes the top one
 * and the head (top element) becomes the second one
 * @head: double pointer to head(top) of stack
 * @n: line number
 * Return: Nothing
 */
void rotr(stack_t **head, unsigned int n)
{
	stack_t *last = *head;
	(void)n;

	/*need at least two elements to swap, else stack remains unchanged*/
	if (*head != NULL && (*head)->next)
	{
		/*get the last element*/
		while (last->next != NULL)
			last = last->next;
		/* do the updates */
		last->next = *head;
		(last->prev)->next = NULL;
		last->prev = NULL;
		(*head)->prev = last;
		*head = last;
	}
}
