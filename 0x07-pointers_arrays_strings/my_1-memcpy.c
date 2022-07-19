#include "main.h"

/**
 * _memcpy - copies memory area
 * @dest: memory address to copy to
 * @src: memory address to copy from
 * @n: the size of memory to fill
 * Return: pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;
	
	/*set values in n addresses of s to b */
	for (; i < n; i++)
		*(dest + i) = src[i];
	return(dest);
}



