#include "lists.h"
#include <stdio.h>
#include <stddef.h>

/**
 * detectLoop - detects presence of a loop in a list
 * @list: the list to check
 * Return: 1 if loop and 0 otherwise
 */
int detectLoop(const listint_t *list)
{
	const listint_t *S = list, *F = list;

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
 * loopNode - returns loopNode in a list
 * @list: the list to check
 * Return: 1 if loop and 0 otherwise
 */
const listint_t *loopNode(const listint_t *list)
{
	const listint_t *S = list, *F = list;

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
 * print_listint_safe - prints all the elements of a listint_t list
 * Description: prints loops in the list too
 * @head: pointer to the list
 * Return: number of nodes in list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t len = 0, printed = 0;
	const listint_t *current, *the_node;

	if (detectLoop(head))
	{
		the_node = loopNode(head);
		/*printf("loopNode: %d\n", the_node->n);*/
	}
	current = head; /*the entry point/ head*/
	for (; current != NULL && printed <= 2; current = current->next, len++)
	{
		if (current == the_node)
		{
			printed++;
			if (printed == 2)
				printf("->");
		}
		printf("[%p] %d\n", (void *)current, current->n);
		if (printed == 2 && current == the_node)
			break;
	}
	return (len);
}
