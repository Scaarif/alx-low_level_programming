#include "main.h"
#include <stddef.h>
#include <stdio.h>

/**
 * _strpbrk - returns pointer to first occurrence of any
 * of the bytes in accept
 * @s: the string
 * @accept: the string whose chars to locate
 * Return: pointer to first occurrence
 */
char *_strpbrk(char *s, char *accept)
{
	int i, j;
	char *new, *orig;
	
	orig = NULL;
	/*locate first occurrence of any of chars in accept*/
	for (j = 0; accept[j] != '\0'; j++)
	{
		for (i = 0; s[i] != '\0'; i++)
		{
			if (s[i] == accept[j])
			{
				new = s + i;
				if (orig == NULL)
				{
					orig = new;
				}
				/* printf("new: %p\n", new); */
				/* printf("%c\n", *new); */
				break;
			}
		}
		new < orig ? orig = new : orig;
		/* printf("orig: %p\n", orig); */
	}
	return(orig);
}



