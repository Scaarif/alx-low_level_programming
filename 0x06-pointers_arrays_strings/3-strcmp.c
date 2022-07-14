#include "main.h"

/**
 * _strcmp - compare two strings
 * @s1: string one
 * @s2: string two
 * Description: returns an int less than 0, 0 or greater
 * if, respectively, 
 * s1 is less than, matches, or greater than s2
 * Return: an integer
 */
int _strcmp(char *s1, char *s2)
{
	int i, res;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		/*for the first disimilar characters*/
		if (s1[i] != s2[i])
		{
			res = s1[i] - s2[i];
		}
		else
		{
			res = 0; /* where s1 == s2*/
		}

		
	}
	return (res);
}

