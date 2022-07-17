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
	int i = 0, res = 0;

	/*find the first dissimilar characters*/
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		i++;
	}
	if (s1[i] != '\0')
		res = s1[i] - s2[i];
	return (res);
}

