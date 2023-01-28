#include "search_algos.h"

/**
 * linear_skip - searches for a value in a sorted list of integers using
 * Jump Search algorithm
 * @list: pointer to the haed of the list of integers to search from
 * @value: the value to search from in the array
 * Return: pointer to first node where value is located and NULL
 * if array is NULL or value not in array)
 *
 * Description: this particular list has an express lane - it is a SKIP list
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *curr = list, *upper_b;

	if (!list)
		return (NULL);
	/* get the block in which value (potentially) recides */
	while (curr->express && curr->express->n < value)
	{
		printf("Value checked at index [%ld] = [%d]\n",
				curr->express->index, curr->express->n);
		curr = curr->express;
	}
	if (curr->express == NULL) /* value in last block */
	{
		upper_b = curr;
		while (upper_b->next->next)
			upper_b = upper_b->next;
		printf("Value found between indexes [%ld] and [%ld]\n",
				curr->index, upper_b->next->index);
		upper_b = upper_b->next;
	}
	else
	{
		printf("Value checked at index [%ld] = [%d]\n",
				curr->express->index, curr->express->n);
		printf("Value found between indexes [%ld] and [%ld]\n",
			curr->index, curr->express->index);
		upper_b = curr->express;
	}
	/* Linear search the block for value */
	while (curr && curr->index <= upper_b->index)
	{
		printf("Value checked at index [%ld] = [%d]\n", curr->index, curr->n);
		if (curr->n == value)
			return (curr);
		if (curr->index == upper_b->index)
			break; /* end of list/block */
		curr = curr->next;
	}
	/* else, value not in block */
	return (NULL);
}
