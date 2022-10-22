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

	/* check that table exists? */
	if (ht)
	{
	/* to add a new node a table ht, create the node */
		node = malloc(sizeof(hash_node_t));
		if (node == NULL)
		{
			free(node);
			return (0); /* failed malloc */
		}
		/* else, check that key isn't empty */
		if (key == NULL || strlen(key) == 0)
			return (0); /* key can't be empty */
		/*node->key = (char *)key;*/
		node->key = strdup(key);
		node->value = strdup(value); /* value must be duplicated */
	/* obtain the index at which to insert the node */
		idx = key_index((const unsigned char *)key, ht->size);
		/*printf("idx: %lu - %s\n", idx, key);*/
	/* check if already occupied (collision status) */
		if ((ht->array)[idx] == NULL) /* vacant */
		{
			node->next = NULL;
			(ht->array)[idx] = node; /* pointer */
		}
	/* if collision, add node to the head of list and update head */
		else /* occupied - collision */
		{
			node->next = (ht->array)[idx];
			/* update head pointer */
			(ht->array)[idx] = node;
		}
		return (1); /* success */
	}
	return (0); /* failure - table undefined */
}

