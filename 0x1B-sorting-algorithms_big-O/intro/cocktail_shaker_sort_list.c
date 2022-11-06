#include "sort.h"

/**
 * cocktail_sort_list - sorts an array (in ascending order) using cocktail shaker sort
 * Description: is an improvement of bubble sort -> uses bidirectional movement
 * fasten the moving of items to the beginning of the array: bubble sort only moves
 * items in one direction
 * @list: double pointer to the linked list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start, *end, *left, *right, *before, *after;
	int sorted = 0;

	/* start and end mark the first and last node to check */
	left = *list; /* start @ head of list */
	right = *list;
	if (left == NULL)
		return; /* empty list */
	while (!sorted)
	{
		sorted = 1;
		/* advance & swap forward */
		for (; right != NULL; right = right->next)
		{
			end = right->next;
			if (end && right->n > end->n)
			{
				sorted = 0;
				/* swap the two nodes, right(before end) & end */
				before = right->prev;
				if (before)
					before->next = end;
				else
					*list = end; /* update head of list */
				right->prev = end;
				after = end->next;
				end->next = right;
				if (after)
					after->prev = right;
				right->next = after;
				end->prev = before;
				print_list(*list); /* print list after swap */
			}
		}
		/* decrease right since the nodes after end are in correct order */
		if (end)
			right = end;
		printf("right: %d\n", right->n);
		printf("start backwards trace with left at: %d\n", right->n);
		/* advance  & swap backwards */
		for (left = right; left->prev != NULL; left = left->prev)
		{
			start = left->prev;
			if (start && start->n > left->n)
			{
				sorted = 0;
				/* swap the two nodes, start(before left) & left */
				before = start->prev;
				if (before)
					before->next = left;
				else
					*list = left; /* update head of list */
				start->prev = left;
				after = left->next;
				left->next = start;
				if (after)
					after->prev = start;
				start->next = after;
				left->prev = before;
				printf("swapped left & start: %d -> %d\n", left->n, start->n);
				print_list(*list); /* print list after swap */
			}
		}
		/* increase left since the element before start are sorted */
		left = start;
		printf("end of backwards->left: %d\n", left->n);
		/* update right to left */
		right = left;
		printf("will start forwards->right @: %d\n", right->n);
	}
}
