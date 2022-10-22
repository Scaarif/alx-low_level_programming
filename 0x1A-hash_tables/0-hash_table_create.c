#include "hash_tables.h"

/**
 * hash_table_create - creates a hash_table
 * @size: the size of the hash table (array)
 * Return: pointer to the newly created hash table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new;
	/*hash_node_t **array;*/
	unsigned long int idx = 0;

	/* allocate memory to the table */
	new = malloc(sizeof(hash_table_t));
	/* if memory allocation fails ...*/
	if (new == NULL)
	{
		free(new);
		return (NULL);
	}
	/* else */
	new->size = size;
	/* allocate memory to  array (size of node_ptr * no_of_nodes)*/
	new->array = malloc(sizeof(hash_node_t *) * size);
	if (new->array == NULL)
	{
		free(new->array);
		return (NULL);
	}
	/* else */
	/*new->array = array;*/
	/* initialize the array? - with a sentinel value (NULL) */
	while (idx++ < (new->size) - 1) /* why though? */
		(new->array)[idx] = NULL;
	return (new);
}

