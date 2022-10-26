#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table
 * @ht: the hash table whose elements to print
 * Return: Nothing
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *curr;
	unsigned long int idx = 0, first = 1;

	/* check that ht is not NULL */
	if (ht)
	{
	/* for every index in the array, print the list */
		printf("{");
		while (idx++ < (ht->size) - 1) /* again, why - 1? (invalid read error) */
		{
			/* if (ht->array)[idx], print it's contents */
			curr = (ht->array)[idx];
			if (curr != NULL)
			{
				/* print the list @ idx */
				while (curr != NULL)
				{
					if (first)
					{ /* a way to ensure the comma @ the end is only added if necessary */
						printf("'%s': '%s'", curr->key, curr->value);
						first = 0;
					}
					else
						printf(", '%s': '%s'", curr->key, curr->value);
					curr = curr->next;
				}
			}
		}
		printf("}\n");
	}
}
