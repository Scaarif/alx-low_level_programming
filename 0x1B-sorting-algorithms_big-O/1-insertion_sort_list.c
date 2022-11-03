#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order (smallest to largest) using insertion sort
 * @list: double pointer to the list to be sorted
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *s_tail, *next, *after, *before, *curr, *curr_prev;

	/* the sorted part is assumed to be the first node */
	s_tail = *list; /* head of list (sorted_tail) */
	if (s_tail) /* list not NULL */
	{
	/* compare the sorted set nodes with the next unsorted node */
		next = s_tail->next;
		while (next)
		{
			if (s_tail->n > next->n) /* swap */
			{
				before = s_tail->prev;
				if (before)
				{
					before->next = next;
					s_tail->prev = next;
					after = next->next;
					next->next = s_tail;
					if (after)
						after->prev = s_tail;
					s_tail->next = after;
				}
				next->prev = before;
				/* compare next with its previous, going backwards */
				curr = next;
				curr_prev = curr->prev;
				while (curr_prev)
				{
					if (curr_prev->n > curr->n)
					{
						/* then swap the nodes */
						before = curr_prev->prev;
						if (before)
							before->next = curr;
						curr_prev->prev = curr;
						after = curr->next;
						curr->next = curr_prev;
						if (after)
							after->prev = curr_prev;
						curr_prev->next = after;
						curr->prev = before;
					}
					/* update curr_prev & curr - to the node before it */
					curr = curr_prev; /* the node we've just swapped */
					curr_prev = curr_prev->prev;
				}
			}
			/* else update s_tail to next */
			s_tail = next;
			/* get next node */
			next = s_tail->next;
		}
	/* place the node in its rightful position - work backwards (towards the head)*/
	/* advance down the list, until tail */
	}
}
