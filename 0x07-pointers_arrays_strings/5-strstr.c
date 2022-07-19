#include "main.h"
#include <stddef.h>

/**
 * _strstr - locates first occurrence substring
 * @haystack: the string
 * @needle: the substring to locate
 * Return: pointer to first occurrence
 */
char *_strstr(char *haystack, char *needle)
{
	char *b;
	char *p;

	while (*haystack != '\0')
	{
		b = haystack;
		p = needle;

		while (*haystack != '\0' && *p != '\0' && *haystack == *p)
		{
			haystack++;
			p++;
		}
		if (!*p)
			return (b);
		haystack = b + 1;
	}
	return (0);
}



