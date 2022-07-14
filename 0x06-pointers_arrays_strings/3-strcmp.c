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
	while ((*s1 && *s2) && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}