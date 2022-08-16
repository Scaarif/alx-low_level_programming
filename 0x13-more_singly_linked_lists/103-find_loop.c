#include "lists.h"
#include <stdio.h>
#include <stddef.h>

/**
 * detectLoop2 - detects presence of a loop in a list
 * @list: the list to check
 * Return: 1 if loop and 0 otherwise
 */
int detectLoop2(listint_t *list)
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
 * find_listint_loop - returns loopNode in a list
 * @head: the list to check
 * Return: pointer to loopNode
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *S = head, *F = head;

	if (detectLoop2(head))
	{
		while (S && F && F->next) /*as long as none of these are NULL*/
		{
			S = S->next;/*move forward a node*/
			F = F->next->next;/*move forward 2 nodes*/
			if (S == F)
				break;
		}
		/*return S to head of list*/
		S = head;
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
	return (NULL);/*where there's no loop*/
}

