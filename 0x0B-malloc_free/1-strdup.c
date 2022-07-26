#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * _strdup - duplicates a string
 * @str: string
 * Return: pointer to duplicate string
 */

char *_strdup(char *str)
{
	unsigned int i, len;
	char *a;

	if (str == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
	len = i + 2;
	/*printf("len: %d\n", len);*/
	a = malloc(sizeof(char) * len);
	for (i = 0; i < len; i++)
		*(a + i) = str[i];
	*(a + i) = '\0'; /*terminate the duplicate*/
	return (a);
}


