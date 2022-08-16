#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * detectLoop1 - detects presence of a loop in a list
 * @list: the list to check
 * Return: 1 if loop and 0 otherwise
 */
int detectLoop1(listint_t *list)
{
	listint_t *S = list, *F = list;

	while (S && F && F->next) /*as long as none of these are NULL*/
	{
		S = S->next;/*move forward a node*/
		F = F->next->next;/*move forward 2 nodes*/
		if (S == F)
			return (1);/*if true*/
	}
	return (0);/*if false*/
}

/**
 * loopNode1 - returns loopNode in a list
 * @list: the list to check
 * Return: 1 if loop and 0 otherwise
 */
listint_t *loopNode1(listint_t *list)
{
	listint_t *S = list, *F = list;

	while (S && F && F->next) /*as long as none of these are NULL*/
	{
		S = S->next;/*move forward a node*/
		F = F->next->next;/*move forward 2 nodes*/
		if (S == F)
			break;
	}
	/*return S to head of list*/
	S = list;
	while (S && F && F->next)
	{
		S = S->next;
		F = F->next;
		if (S == F)
		{
			/*printf("S: %d\n", S->n);*/
			/*printf("F: %d\n", F->n);*/
			break;
		}
	}
	return (S);/*meeting node == loopNode*/
}
/**
 * free_listint_safe - prints all the elements of a listint_t list
 * Description: prints loops in the list too
 * @head: pointer to the list
 * Return: number of nodes in list
 */
size_t free_listint_safe(listint_t **head)
{
	size_t len = 0, printed = 0;
	listint_t *current, *the_node;

	if (detectLoop1(*head))
	{
		the_node = loopNode1(*head);
		/*printf("loopNode: %d\n", the_node->n);*/
	}
	for (; (*head) != NULL && printed <= 2; len++)
	{
		current = *head; /*the entry point/ head*/
		(*head) = (*head)->next;/*update head b4 freeing it*/
		if (current == the_node)
		{
			printed++;
		}
		/*printf("[%p] %d\n", (void *)current, current->n);*/
		if (printed == 2 && current == the_node)
			break;
		/*printf("freed: %d\n", current->n);*/
		free(current);
	}
	*head = NULL;
	return (len);
}
