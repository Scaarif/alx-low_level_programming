#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: the string
 * @accept: the substring to locate
 * Return: length 
 */
unsigned int _strspn(char *s, char *accept)
{
	int i, len = 0, new, j;
	
	/*locate first occurrence of chars in accept*/
	for (j = 0; accept[j] != '\0'; j++)
	{
		for (i = 0; s[i] != '\0'; i++)
		{
			if (s[i] == accept[j])
			{
				new = i;
				break;
			}
		}
		new > len ? len = new : len;
	}
	return(len + 1);
}



