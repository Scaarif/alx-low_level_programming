#include "hash_tables.h"

/**
 * hash_table_get - retrieves a value associated with a key
 * @ht: the hash table to search
 * @key: the key whose value to retrieve
 * Return: the retrieved value
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int idx;
	hash_node_t *curr;

	if (ht && key && strlen(key) > 0)
	{
		/* get the idx of the key in the hash table */
		idx = key_index((const unsigned char *)key, ht->size);
		/* check that idx is in ht->array and return node->value */
		if ((ht->array)[idx] != NULL)
		{
			if (strcmp(((ht->array)[idx])->key, key) == 0)
				return (((ht->array)[idx])->value);
			/* else, check down the list at idx */
			for (curr = (ht->array)[idx]; curr != NULL; curr = curr->next)
			{
				if (strcmp(curr->key, key) == 0)
					return (curr->value);
			}
		}
		/* else return NULL (key not found?) */
	}
	return (NULL);
}
