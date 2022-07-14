#include "main.h"

/**
 * leet - encodes a string with 1337
 * @s: the string
 * Return: string
 */
char *leet(char *s)
{
	int i = 0;

	/**
	 * check the characters e, E, a, A, o, O, t, T, l or L
	 * and substitute them with letters as necessary
	 */
	while (s[i] != '\0')
	{
		if (s[i] == 'a' || s[i] == 'A')
			s[i] = '4';
		else if (s[i] == 'e' || s[i] == 'E')
			s[i] = '3';
		else if (s[i] == 'o' || s[i] == 'O')
			s[i] = '0';
		else if (s[i] == 't' || s[i] == 'T')
			s[i] = '7';
		else if (s[i] == 'l' || s[i] == 'L')
			s[i] = '1';
		i++;
	}
	return (s);
}

