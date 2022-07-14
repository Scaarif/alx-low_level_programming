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
	ptr = _strcat(s1, s2);
	printf("%s", s1);
	printf("%s", s2);
	printf("%s", ptr);
	return (0);
}
/**
 * _strcat - concatenates two strings
 * @dest: original string
 * @src: string to append to original
 * Return: pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	char *p;
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
	p = &dest[i + 1];
	/*append the rest of the characters in src to dest*/
	for (j = 0; src[j] != '\0'; j++)
	{
		*(p + j) = src[j];
	}
	dest[i + j + 1] = '\0';
	return (dest);
}

