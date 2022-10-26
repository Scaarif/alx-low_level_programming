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
 int ret;
 ht = hash_table_create(1024);
 ret = hash_table_set(ht, "betty", "cool");
 printf("ret: %d\n", ret);
 ret = hash_table_set(ht, "", "cool");
 printf("ret: %d\n", ret);
 ret = hash_table_set(ht, NULL, "cool");
 printf("ret: %d\n", ret);
 ret = hash_table_set(ht, "hetairas", "cool");
 printf("ret: %d\n", ret);
 ret = hash_table_set(ht, "mentioner", "cool");
 printf("ret: %d\n", ret);
 return (EXIT_SUCCESS);
}
