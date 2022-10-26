#include "hash_tables.h"

/**
 * shash_table_create - creates a sorted HahsTable
 * @size: the size of the table array
 * Return: pointer to the created table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *table;
	unsigned long int idx = 0;

	/* create the table - by memory allocation */
	if (size > 0)
	{
		table = malloc(sizeof(shash_table_t));
		if (table == NULL)
		{
			free(table);
			return (NULL); /* malloc failure */
		}
		/* else */
		table->size = size;
		/* allocate memory to table array */
		table->array = malloc(sizeof(shash_node_t *) * size);
		if (table->array == NULL)
		{
			free(table->array);
			return (NULL); /* malloc failure */
		}
		/* initialize the array buckets */
		for (; idx < size; idx++)
			(table->array)[idx] = NULL;
		/* initialize the other member values */
		table->shead = NULL;
		table->stail = NULL;
	}
	else
		table = NULL;
	return (table);
}

/**
 * update_shash_table_sorted_list - inserts an element into the HashTable's
 * sorted list
 * @ht: pointer to the hash table
 * @node: pointer to the node to insert
 * Return: Nothing, always succeeds
 */
void update_shash_table_sorted_list(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *insert, *before;

	if (ht->shead == NULL) /* first bucket of table == node */
	{
		node->sprev = NULL;
		node->snext = NULL;
		ht->shead = node;
		ht->stail = node;
	}
	else /* buckets already exist, compare */
	{
		if (strcmp((ht->shead)->key, node->key) >= 0)
		{/* node should come before the shead_node - new shead */
			node->snext = ht->shead;
			node->sprev = NULL;
			(ht->shead)->sprev = node;
			ht->shead = node; /* update table's shead */
		}
		else if (strcmp((ht->stail)->key, node->key) <= 0)
		{ /* node should become the new tail */
			node->sprev = ht->stail;
			node->snext = NULL; /* last bucket */
			(ht->stail)->snext = node;
			ht->stail = node; /* update */
		}
		else /* node should be somewhere in the middle */
		{ /* search for proper location to insert */
			for (insert = ht->shead; insert != ht->stail; insert = insert->snext)
			{
				if (strcmp(insert->key, node->key) >= 0)
					break; /*insert @ insert->sprev (at before) */
				before = insert;
			}
			node->sprev = before;
			node->snext = insert; /*insert just before insert_node */
			before->snext = node;
			insert->sprev = node;
		}
	}
}

/**
 * shash_table_set - inserts an element (bucket) into the HashTable
 * @ht: pointer to the hash table
 * @key: the key, string, of element to insert
 * @value: the value, string, associated with the key
 * Return: 1 on success and 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	shash_node_t *node;

	if (ht && key && strlen(key) > 0) /* check that table exists */
	{ /* check if the key already exists in the table (don't recreate) */
		idx = key_index((const unsigned char *)key, ht->size);
		if ((ht->array)[idx] != NULL)
		{
			for (node = (ht->array)[idx]; node != NULL; node = node->next)
			{
				if (strcmp(node->key, key) == 0)
				{
					free(node->value); /* to update its value to new value */
					node->value = strdup(value); /* i.e. assign new value */
					return (1); /* successfully updated */
				}
			}
		} /* else, create new node - malloc it & assign values if successful */
		node = malloc(sizeof(shash_node_t));
		if (node == NULL)
		{
			free(node);
			return (0); /* malloc failure */
		}
		node->key = strdup(key);
		node->value = strdup(value);
		if ((ht->array)[idx] == NULL) /* idx vacant */
		{
			(ht->array)[idx] = node;
			node->next = NULL;
		}
		else /* collision @ idx - Chain resolve by inserting @ head */
		{
			node->next = (ht->array)[idx];
			(ht->array)[idx] = node; /* update the list head */
		} /* update sorted list ('key' based elements) */
		update_shash_table_sorted_list(ht, node);
		return (1); /* success */
	} /* return failure, otherwise */
	return (0);
}

/**
 * shash_table_get - returns a value associated with a given key
 * @ht: the HahsTable to search for value from
 * @key: the key whose associated value to return
 * Return: the value or NULL if not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int idx;
	shash_node_t *node;

	/* get the idx associated with the key */
	if (ht && key && strlen(key) > 0)
	{
		idx = key_index((const unsigned char *)key, ht->size);
		/* search for the key in table and return its value */
		node = (ht->array)[idx];
		if (node) /* value at idx not NULL */
		{
			if (strcmp(node->key, (char *)key) == 0)
				return (node->value);
			/* else, search the list at idx */
			while (node != NULL)
			{
				if (strcmp(node->key, (char *)key) == 0)
					return (node->value);
				node = node->next;
			}
			/* else */
			return (NULL); /* key not found */
		}
		return (NULL); /* (ht->array)[idx] vacant */
	}
	return (NULL); /* ht is NULL (undefined) */
}

/**
 * shash_table_print - prints the HashTable elements in order (sorted)
 * @ht: the hash table to print
 * Return; Nothing
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *curr;
	int first = 1;

	if (ht)
	{
		curr = ht->shead;
		printf("{");
		while (curr != NULL)
		{
			if (first)
			{
				printf("'%s': '%s'", curr->key, curr->value);
				first = 0;
			}
			else
				printf(", '%s': '%s'", curr->key, curr->value);
			curr = curr->snext;
		}
		printf("}\n");
	}
}

/**
 * shash_table_print_rev - prints the HashTable elements in reversed
 * (sorted) order
 * @ht: the hash table to print
 * Return; Nothing
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *curr;
	int first = 1;

	if (ht)
	{
		curr = ht->stail;
		printf("{");
		while (curr != NULL)
		{
			if (first)
			{
				printf("'%s': '%s'", curr->key, curr->value);
				first = 0;
			}
			else
				printf(", '%s': '%s'", curr->key, curr->value);
			curr = curr->sprev;
		}
		printf("}\n");
	}
}

/**
 * shash_table_delete - deletes the HashTable, freeing all
 * allocated mmeory
 * @ht: pointer to the table to delete
 * Return: Nothing
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *curr, *to_free;

	if (ht)
	{
		/* free all nodes in table */
		curr = ht->shead;
		while (curr != NULL)
		{
			to_free = curr;
			curr = curr->snext;
			free(to_free->key); /* was duplicated during creation */
			free(to_free->value); /* was duplicated during creation */
			free(to_free); /* free the node itself */
		}
		/* free the array */
		free(ht->array);
		/* free the table itself */
		free(ht);
	}
}

