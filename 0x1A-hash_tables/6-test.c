#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

void _shash_table_print_array(const shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *p;
	char n;

	if (!ht)
		return;
	for (i = 0; i < ht->size; i++)
	{
		p = ht->array[i];
		printf("[%lu]", i);
		n = 0;
		while (p)
		{
			if (n)
				printf(", ");
			printf("'%s': '%s'", p->key, p->value);
			p = p-> next;
			n = 1;
		}
		printf("\n");
	}
}

void _shash_table_print_sorted(const shash_table_t *ht)
{
	shash_node_t *p;
	char n;

	if (!ht)
		return;
	printf("{");
	n = 0;
	p = ht->shead;
	while (p)
	{
		if (n == 1)
		{
			printf(", ");
		}
		printf("'%s': '%s'", p->key, p->value);
		n = 1;
		p = p->snext;
	}
	printf("}\n");
}

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
	shash_table_t *ht;
	int ret;

	ht = shash_table_create(10);
	ret = shash_table_set(ht, "Holberton", "is cool");
	printf("%d\n", ret);
	_shash_table_print_array(ht);
	_shash_table_print_sorted(ht);
	ret = shash_table_set(ht, "Holberton", "is soooo cooool");
	printf("%d\n", ret);
	_shash_table_print_array(ht);
	_shash_table_print_sorted(ht);
	ret = shash_table_set(ht, "Holberton", "is awesome");
	printf("%d\n", ret);
	_shash_table_print_array(ht);
	_shash_table_print_sorted(ht);
	return (EXIT_SUCCESS);
}
