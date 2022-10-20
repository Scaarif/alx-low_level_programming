#include "hash_tables.h"

/**
 * key_index - maps a key to an index in the hash table
 * @key: the string to map (i.e. hash)
 * @size: the size of the array of the hash table (i.e. m)
 * Return: the index
 */
unsigned long int key_index(const unsigned char *key,
		unsigned long int size)
{
	unsigned long int idx;

	/* get the hash of the string, key */
	idx = hash_djb2(key);
	/* map the hash (of  key) to an index in array */
	idx %= size;  /* ie. idx = idx_hash % size */
	return (idx);
}

