#include "main.h"
#include <stdio.h>
/**
 * main - check code
 * Return: always 0
 */

int main(void)
{
	char s1[98] = "Hello ";
	char s2[] = "World!\n";
	char *ptr;

	printf("%s\n", s1);
	printf("%s", s2);
	ptr = _strncat(s1, s2, 1);
	printf("%s\n", s1);
	printf("%s", s2);
	printf("%s\n", ptr);
	ptr = _strncat(s1, s2, 1024);
	printf("%s", s1);
	printf("%s", s2);
	printf("%s", ptr);
	return (0);
}
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

