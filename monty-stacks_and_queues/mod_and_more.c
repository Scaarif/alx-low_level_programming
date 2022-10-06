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
