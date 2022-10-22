#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"
/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
 hash_table_t *ht;
 char *key;
 char *value;
 ht = hash_table_create(1024);
 key = strdup("Tim");
 value = strdup("Britton");
 hash_table_set(ht, key, value);
 key[0] = '\0';
 value[0] = '\0';
 free(key);
 free(value);
 
 hash_table_print(ht);
 hash_table_delete(ht);
 return (EXIT_SUCCESS);
}
