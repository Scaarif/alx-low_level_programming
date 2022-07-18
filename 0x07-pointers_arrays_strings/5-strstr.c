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
	int i, n = 0, t, _true;
	char *p;
	/*locate first occurrence of needle*/
	for (i = 0; haystack[i] != '\0'; i++)
	{
		if (haystack[i] == needle[n])
		{
			if (haystack[i + 1] == needle[n + 1])
			{
				t = i;
				_true = 1;
				while (needle[n] != '\0' && haystack[t] != '\0')
				{
					if (needle[n] != haystack[t])
					{
						_true *= 0;
					}
					t++;
					n++;
				}
			}
			if (_true > 0)
			{
				p = haystack + i;
				break;
			}
		}
	}
	return (p ? p : NULL); /* return p if assigned, else return NULL*/
}



