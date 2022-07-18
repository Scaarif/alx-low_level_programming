#include "main.h"
#include <stddef.h>

/**
 * _strchr - locates a character in a string
 * @s: the string
 * @c: the character to locate
 * Return: pointer to first occurrence of character
 */
char *_strchr(char *s, char c)
{
	int i = 0;
	char *p;
	
	/*locate first occurrence of c*/
	for (; s[i] != '\0'; i++)
	{
		if (s[i] == c)
		{
			p = (s + i);
			break;
		}
		else
		{
			p = NULL;
		}
	}
	return(p);
}



