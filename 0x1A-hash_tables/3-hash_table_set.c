#include "hash_tables.h"

/**
 * hash_table_set - adds an element to the hash table
 * @ht: the hash table to add an element to
 * @key: the element's key
 * @value: the element's value
 * Return: 1 if successful and 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key,
		const char *value)
{
	hash_node_t *node;
	unsigned long int idx;

	if (ht)
	{
		if (key == NULL || strlen(key) == 0)
			return (0); /* key can't be empty */
		idx = key_index((const unsigned char *)key, ht->size);
		/* check for the key in the existing node and chain-list of ht->array[idx] */
		for (node = (ht->array)[idx]; node != NULL; node = node->next)
		{
			if (strcmp(node->key, key) == 0)
			{
				free(node->value);
				node->value = strdup(value);
				return (1); /* successfully update the node */
			}
		} /* if not existent, add a new node to table, create the node first */
		node = malloc(sizeof(hash_node_t));
		if (node == NULL)
		{
			free(node);
			return (0); /* failed malloc */
		}
		node->key = strdup(key);
		node->value = strdup(value); /* value must be duplicated */
		if ((ht->array)[idx] == NULL) /* vacant */
		{
			node->next = NULL;
			(ht->array)[idx] = node; /* pointer */
		} /* if collision, add node to the head of list and update head */
		else /* occupied - possible collision */
		{
			node->next = (ht->array)[idx];
			(ht->array)[idx] = node;
		}
		return (1); /* success */
	}
	return (0); /* failure - table undefined */
}

