#include "main.h"

/**
 * rev_string - prints a string in reverse to stdout
 * @s: string argument
 * Return: void
 */
void rev_string(char *s)
{
	int len = 0, j = 0, a_len;
	char i = s[len];
	char *str = s;

	while (i != '\0')
	{
		len++;
		i = s[len];
	}

	a_len = len - 1;
	while (a_len >= 0)
	{
		s[j] = str[a_len];
		a_len--;
		j++;
	}
}


int len = 0, j;
	char i = s[len], hold;

	while (i != '\0')
	{
		len++;
		i = s[len];
	}

    j = 0;
	while (j < len / 2)
	{
		hold = s[j];
		s[j] = s[len];
		s[len] = hold;
        j++;
        len--;
	}