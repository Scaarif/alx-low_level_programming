#include "main.h"

/**
 * _memset - fills memory with a constant byte
 * @s: memory address to fill
 * @b: the constant byte to fill memory with
 * @n: the size of memory to fill
 * Return: pointer to memory
 */
char *_memset(char *s, char b, unsigned int n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		s[i] = b;
		i++;
		n--;
	}
	return (s);
}
