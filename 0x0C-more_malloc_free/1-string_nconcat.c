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
	len = i;
	return (len);
}

/**
 * string_nconcat - concatenates two strings
 * @s1: string one
 * @s2: string two
 * @n: bytes of s2 to concatenate
 * Descristrtion: treates NULL as an emstrty string
 * Return: strointer to allocated memory of new string
 * :else NULL
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *str;
	unsigned int len1, i, c;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	len1 = (unsigned int)get_len(s1);
	str = malloc((len1 + n + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	for (i = 0, c = 0; i < (len1 + n); i++)
	{
		if (i < len1)
			str[i] = s1[i];
		else
			str[i] = s2[c++];
	}
	str[i] = '\0';

	return (str);
}


