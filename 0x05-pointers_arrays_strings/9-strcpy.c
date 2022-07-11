#include "main.h"
#include <stdio.h>

int main(void)
{
	char s1[98];
	char *ptr;

	ptr = _strcpy(s1, "First, solve the problem. Then, write the code\n");
	printf("%s", s1);
	printf("%s", ptr);
	return (0);
}

/**
 * *_strcpy - copies string pointed by a pointer to another pointer
 * @dest: pointer to copy to
 * @src: pointer o copy from
 * Return: a char
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i]; /*add the new null character at end of the dest string*/
	return (dest);
}
