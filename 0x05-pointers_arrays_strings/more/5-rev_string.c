#include "main.h"
#include <stdio.h>

/**
 * rev_string - reverse string
 * Return: nothing
 */

void rev_string(char *s)
{
	int i, j, k, count;
	char hold;

	for (k = 0; s[k] != '\0'; k++);
	j = k - 1;
	count = j / 2;
	for (i = 0; i <= count; i++, j--)
	{
		hold = s[i];
		s[i] = s[j];
		s[j] = hold;
	}
}



