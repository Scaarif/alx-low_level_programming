#include "main.h"

/**
 * get_endianness - checks the endianness
 * Return: 1 or 0 based on endianess
 */
int get_endianness(void)
{
	unsigned int i = 1;
	char *c = (char *)&i;/*cast the address into a string*/

	return (*c - '0');/*1 means LE and 0 BE*/
}

