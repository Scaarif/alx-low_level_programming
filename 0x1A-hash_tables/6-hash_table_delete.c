#include "hash_tables.h"

/**
 * hash_table_delete - deletes the hash table, ht
 * @ht: pointer to the hash table
 * Return: Nothing
 */
void hash_table_delete(const hash_table_t *ht)
{
	hash_node_t *curr, *to_free;
	unsigned long int idx = 0;
	/* check that ht isn't NULL */
	if (ht)
	{
	/* ht contains an array with lists (nodes) */
		/*go through the array freeing each list */
		while (idx++ < ht->size)
		{
	/* every allocated memory has to be freed - the table, the array & nodes */
			curr = (ht->array)[idx];
			if (curr != NULL)
			{
				/* free nodes in list at idx */
				while (curr != NULL)
				{
					to_free = curr;
					curr = curr->next;
					free(to_free->value); /* was duplicated */
					free(to_free);
				}
			}
		}
		/* all nodes freed, free ht->array */
		free(ht->array);
		/* free the table itself */
		free((hash_table_t *)ht);
	}
}

