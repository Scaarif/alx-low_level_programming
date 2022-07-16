#include "main.h"
#include <stdio.h>
#include <string.h>

int _strlen(char *);

int main(void)
{
	char *str;
	int len;

	str = "My first strlen!";
	len = _strlen(str);
	printf("%d\n", len);
	printf("strlen: %ld\n", strlen(str));
	return (0);
}

int _strlen(char *s)
{
	/*return the length of a string input*/
	int i;

	for (i = 0; s[i] != '\0'; i++)
	i++;
	return (i);
}

