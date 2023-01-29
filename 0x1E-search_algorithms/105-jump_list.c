#include "search_algos.h"
#include <math.h>

/**
 * min - returns the smaller of two integers
 * @a: integer one
 * @b: integer two
 * Return: the samller of a and b
 */
size_t min(size_t a, size_t b)
{
	if (a > b)
		return (b);
	return (a);
}

/**
 * traverse_list - traverses list to node at step index
 * @curr: pointer to the current position in list
 * @step: integer steps to take (past current node)
 * Return: pointer to node at step index
 */
listint_t *traverse_list(listint_t *curr, size_t step)
{
	size_t i = 0;

	for (; i < step && curr->next; i++)
		curr = curr->next;
	return (curr);
}

/**
 * jump_list - searches for a value in a sorted list of integers using
 * Jump Search algorithm
 * @list: pointer to the haed of the list of integers to search from
 * @size: the size of the list
 * @value: the value to search from in the array
 * Return: pointer to first node where value is located and NULL
 * if array is NULL or value not in array)
 */

listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step;
	listint_t *pos, *curr = list;

	if (!list || size == 0)
		return (NULL);
	step = sqrt(size);
	/* get the block in which value (potentially) recides */
	while ((pos = traverse_list(curr, step)) && value > pos->n)
	{
		printf("Value checked at index [%ld] = [%d]\n", pos->index, pos->n);
		if (pos->next == NULL) /* end of list, value not in list */
			break;
		curr = pos;
	}
	if (pos->next != NULL) /* value not in last block */
	{
		printf("Value checked at index [%ld] = [%d]\n", pos->index, pos->n);
	}
	/* Linear search the block for value */
	printf("Value found between indexes [%ld] and [%ld]\n",
			curr->index, pos->index);
	while (curr && curr->index <= pos->index)
	{
		printf("Value checked at index [%ld] = [%d]\n", curr->index, curr->n);
		if (curr->n == value)
			return (curr);
		curr = curr->next;
	}
	/* else, value not in block */
	return (NULL);
}
