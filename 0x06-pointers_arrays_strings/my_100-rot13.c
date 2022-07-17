#include "main.h"
#include <stdio.h>
/**
 * main - check code
 * Return: always 0
 */

int main(void)
{
	/*char str[] = "ROT13 (\"rotate by 13 places\", sometimes hyphenated ROT-13) is a simple letter substitution cipher.\n"; */
	char str[] = "ROT13 system!\n";
	char *ptr;

	ptr = rot13(str);
	printf("%s\n", ptr);
	printf("%s\n", str);
	return (0);
}
/**
 * rot13 - encodes a string with rot13
 * Description: rotate each letter to the 13th letter from it
 * @s: the string
 * Return: string
 */
char *rot13(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		/*rotate small letters*/
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] = s[i] + 13;
			if (s[i] > 'z')
			{
				s[i] = (s[i] - 'z') + ('a' - 1);
			}
		}
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] = s[i] + 13;
			if (s[i] > 'Z')
			{
				s[i] = (s[i] - 'Z') + ('A' - 1);
			}
		}
		i++;
	}
	return (s);
}

