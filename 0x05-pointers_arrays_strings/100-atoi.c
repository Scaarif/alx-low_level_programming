#include "main.h"
#include <stdio.h>


/**
 * _atoi - Convert a string to integer.
 * @s: char array string
 * Description: Number in the string can be preceded by an infinite
 * number of characters.
 * take into account all -/+ signs before the number.
 * return 0 if there are no numbers in the string.
 * Not allowed to hard-code special values o create an array variable.
 * Return: first integer found in string
 */

int _atoi(char *s)
{
	int i = 0;
	int h, p;

	h = 0;
	p = -1;
	while (s[i] != '\0')
	{
		if (s[i] == '-')
			p *= -1;

		if (s[i] > 47 && s[i] < 58)
		{
			if (h < 0)
            {
				h = (h * 10) - (s[i] - '0');
            }
			else
            {
				h = (s[i] - '0') * -1;
            }
			if (s[i + 1] < 48 || s[i + 1] > 57)
			{
                	break;
            }
		}
        i++;
	}
	if (p < 0)
		h *= -1;

	return (h);
}
