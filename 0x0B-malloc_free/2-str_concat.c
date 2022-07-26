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

	if (s1 == NULL)
	{
		len += 0;
	}
	else
	{
		for (i = 0; s1[i] != '\0'; i++)
		len += i;
	}
	if (s2 == NULL)
	{
		len += 0;
	}
	else
	{
		for (i = 0; s2[i] != '\0'; i++)
		len += i;
	}
	a = malloc(sizeof(char) * len);
	if (a == NULL)
		return (NULL);
	if (s1 != NULL)
	{
		for (i = 0; i < len && s1[i] != '\0'; i++)
			*(a + i) = s1[i];
	}
	else
	{
		i = 0;
	}
	for (j = 0; i < len && s2 != NULL; i++, j++)
		*(a + i) = s2[j];
	*(a + i) = '\0'; /*terminate the concatenated string*/
	return (a);
}


