#include "main.h"

/**
 * _strncat - concatenates two strings
 * @dest: original string
 * @src: string to append to original
 * @n: number of characters to append fron src
 * Return: pointer to dest
 */
char *_strncat(char *dest, char *src, int n)
{
	char *p;
	int i, j;

	/* get length of dest string*/
	for (i = 0; dest[i] != '\0'; i++)
	p = &dest[i + 1];
	/*append n characters in src to dest*/
	for (j = 0; j < n && src[j] != '\0'; j++)
	{
		*(p + j) = src[j];
	}
	dest[i + j + 1] = '\0';
	return (dest);
}

