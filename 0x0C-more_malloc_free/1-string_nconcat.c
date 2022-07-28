#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * get_len - calculates len of a string
 * @s: the string
 * Return: int len
 */
int get_len(char *s)
{
	int i, len;

	if (s == NULL)
		len = 0;
	else
	{
		for (i = 0; s[i] != '\0'; i++)
			;
	}
	len = i + 1;
	return (len);
}

/**
 * string_nconcat - concatenates two strings
 * @s1: string one
 * @s2: string two
 * @n: bytes of s2 to concatenate
 * Description: treates NULL as an empty string
 * Return: pointer to allocated memory of new string
 * :else NULL
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *str;
	unsigned int i, c, len1, len2, total = 0;

	len1 = (unsigned int) get_len(s1);
	total += len1;
	len2 = (unsigned int) get_len(s2);
	if (len2 <= n)
		total += len2 + 1;/* account for a terminating character */
	else
		total += n + 1;
	str = malloc(sizeof(char) * total);
	if (str == NULL)
		return (NULL);
	i = 0;
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	for (i = 0, c = 0; i < (total - 1); i++)
	{
		if (i < len1)
			str[i] = s1[i];
		else
			str[i] = s2[c++];
	}
	str[i] = '\0';
	return (str);
}


