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
	{ /* ht contains an array with lists (nodes) */
		if (ht->size == 1)
		{
			curr = (ht->array)[idx];
			if (curr != NULL)
			{ /* free nodes in list at idx */
				for (; curr != NULL; curr = curr->next)
				{
					to_free = curr;
					free(to_free->key); /* was duplicated */
					free(to_free->value); /* was duplicated */
					free(to_free);
				}
			}
		}
		else
		{
			while (idx++ < (ht->size) - 1)
			{ /* every allocated memory has to be freed: the table, the array & nodes */
				curr = (ht->array)[idx];
				if (curr != NULL)
				{ /* free nodes in list at idx */
					while (curr != NULL)
					{
						to_free = curr;
						curr = curr->next;
						free(to_free->key); /* was duplicated */
						free(to_free->value); /* was duplicated */
						free(to_free);
					}
				}
			}
		} /* all nodes freed, free ht->array */
		free(ht->array);
		free((hash_table_t *)ht); /* free the table itself */
	}
}

