#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: the string
 * @accept: the substring to locate
 * Return: length
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, j, _true;

	for (i = 0; *(s + i) != '\0'; i++)
	{
		_true = 1;
		for (j = 0; *(accept + j) != '\0'; j++)
		{
			if (*(s + i) == *(accept + j))
			{
				_true = 0;
				break;
			}
		}
		if (_true == 1)
			break;
	}
	return (i);
}



