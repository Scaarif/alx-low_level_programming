#include "main.h"

/**
 * _strncpy - copy part of a string
 * @dest: original string
 * @src: string to copy
 * @n: no of characters to copy
 * Return: pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	char *p;
	int i;

	p = dest; /*array decay*/
	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		*(p + i) = src[i]; /*what if i > len of src - write null characters as below*/
	}
	/*if strlen(src) < n; n - len null(s)*/
	for (; i < n; i++)
	{
		*(p + i) = '\0';
	}
	return (dest);
}

