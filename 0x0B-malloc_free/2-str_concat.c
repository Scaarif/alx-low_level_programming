#include "main.h"
#include <stdlib.h>
/**
 * str_concat - concatenates two strings
 * @s1: string one
 * @s2: string two
 * Return: pointer to concatenated string
 */

char *str_concat(char *s1, char *s2)
{
	unsigned int i, len = 0, j;
	char *a;

	if (s1 == NULL || s2 == NULL)
		len += 0;
	for (i = 0; s1[i] != '\0'; i++)
	len += i;
	for (i = 0; s2[i] != '\0'; i++)
	len += i;
	a = malloc(sizeof(char) * len);
	for (i = 0; i < len && s1[i] != '\0'; i++)
		*(a + i) = s1[i];
	for (j = 0; i < len; i++, j++)
		*(a + i) = s2[j];
	*(a + i) = '\0'; /*terminate the concatenated string*/
	return (a);
}


