#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * add_newline - adds newline character to end of string
 * @s: string
 * Return: pointer to modified string
 */

char *add_newline(char *s)
{
	int len, i;
	char *p;

	for (i = 0; s[i] != '\0'; i++)
	len = i;
	p = malloc(sizeof(char) * (len + 1));
	/*duplicate s and add newline character at the end*/
	for (i = 0; i < len; i++)
		*(p + i) = s[i];
	*(p + i) = '\n';
	*(p + (i + 1)) = '\0';
	return (p);
}
/**
 * argstostr - concatenates all the arguments of the program
 * @ac: args count
 * @av: args pointer
 * Description: each arg is followed by a \n in the new string
 * Return: pointer to new str or NULL if ac == 0 or av == NULL
 */

char *argstostr(int ac, char **av)
{
	char *s, *str;
	int i, a_size = 0, j, ptr_pos;

	if (ac == 0 || av == NULL)
		return (NULL);
	/*printf("ac: %d\n", ac);*/
	/*a_size = sum of length of all args*/
	for (i = 0; i < ac; i++)
	{
		str = av[i];
		/*printf("av[i]: %s\n", av[i]);*/
		/*printf("av[i]: %s\n", str);*/
		for (j = 0; str[j] != '\0'; j++)
		a_size += j;
	}
	/*printf("a_size: %d\n", a_size);*/
	s = malloc(sizeof(char) * a_size);
	ptr_pos = 0;
	for (i = 0; i < ac; i++)
	{
		str = av[i];
		for (j = 0; str[j] != '\0'; j++)
		{
			*(s + ptr_pos) = *(str + j);
			ptr_pos++;
			/*so it prints the whole string - not first char*/
		}
		/*add newline character*/
		*(s + ptr_pos) = '\n';
		ptr_pos++;
	}
	return (s);
}


