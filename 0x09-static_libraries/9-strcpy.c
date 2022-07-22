#include "main.h"

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
