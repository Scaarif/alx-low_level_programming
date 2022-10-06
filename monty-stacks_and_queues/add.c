#include "monty.h"

/**
 * add - adds the two element at the top of the stack
 * Description: i.e. the head (topmost) and head->next
 * and stores the result in head->next, popping head
 * @head: double pointer to head(top) of stack
 * @n: line number
 * Return: Nothing
 */
void add(stack_t **head, unsigned int n)
{
	stack_t *temp;
	(void)n;

	if (*head != NULL)
		temp = *head;
	if (temp->next)/*then we have at least two elements*/
	{
		*head = temp->next;/*i.e the 2nd element*/
		(*head)->n = temp->n + (*head)->n;
		(*head)->prev = NULL;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
}

/**
 * nop - does nothing to the top of the stack
 * @head: double pointer to head(top) of stack
 * @n: line number
 * Return: Nothing
 */
void nop(stack_t **head, unsigned int n)
{
	(void)n;
	(void)head;
}

/**
 * sub - subtracts the two element at the top of the stack
 * Description: i.e. the head from head->next
 * and stores the result in head->next, popping head
 * @head: double pointer to head(top) of stack
 * @n: line number
 * Return: Nothing
 */
void sub(stack_t **head, unsigned int n)
{
	stack_t *temp;
	(void)n;

	if (*head != NULL)
		temp = *head;
	if (temp->next)/*then we have at least two elements*/
	{
		*head = temp->next;/*i.e the 2nd element*/
		(*head)->n = (*head)->n - temp->n;
		(*head)->prev = NULL;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
}

/**
 * div_ - divides the two element at the top of the stack
 * Description: i.e. the head->next by head
 * and stores the result in head->next, popping head
 * @head: double pointer to head(top) of stack
 * @n: line number
 * Return: Nothing
 */
void div_(stack_t **head, unsigned int n)
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
			(*head)->n = (*head)->n / temp->n;
		(*head)->prev = NULL;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
}

/**
 * mul - multiplies the two element at the top of the stack
 * Description: i.e. the head & head->next
 * and stores the result in head->next, popping head
 * @head: double pointer to head(top) of stack
 * @n: line number
 * Return: Nothing
 */
void mul(stack_t **head, unsigned int n)
{
	stack_t *temp;
	(void)n;

	if (*head != NULL)
		temp = *head;
	if (temp->next)/*then we have at least two elements*/
	{
		*head = temp->next;/*i.e the 2nd element*/
		(*head)->n = (*head)->n * temp->n;
		(*head)->prev = NULL;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
}
