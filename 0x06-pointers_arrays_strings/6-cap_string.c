#include "main.h"

/**
 * cap_string - capitalize each word of a string
 * @s: the string
 * Return: string
 */
char *cap_string(char *s)
{
	int i = 0;

	/* check that the character after space is a letter first*/
	while (s[i] != '\0')
	{
		/*check first letter*/
		if (s[0] >= 'a' && s[0] <= 'z')
		{
			s[0] = s[0] - 32;
		}
		/*check letters folowing the space character*/
		else if ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n' ||
		s[i] == ',' || s[i] == ';' || s[i] == '!' || s[i] == '?'
		|| s[i] == '"' || s[i] == '(' || s[i] == '{' || s[i] == ')'
		|| s[i] == '}')
		&& (s[i + 1] >= 'a' && s[i + 1] <= 'z'))
		{
			s[i + 1] = s[i + 1] - 32;
		}
		i++;
	}
	return (s);
}

