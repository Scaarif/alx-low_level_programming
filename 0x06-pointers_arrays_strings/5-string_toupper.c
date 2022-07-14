#include "main.h"

/**
 * string_toupper - changes all lowercase letters to uppercase
 * @s: the string
 * Return: string
 */
char *string_toupper(char *s)
{
	int i = 0;
	/* check that the caharacter is a letter first*/
	while (s[i] != '\0')
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] = s[i] - 32;
		}
		i++;
	}
	return (s);
}

