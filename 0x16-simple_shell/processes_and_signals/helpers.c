#include "main.h"

/**
 * _write - print simple lines to stdout
 * @buf: buffer to hold string to write
 * @str: accompanying string, say name
 * @msg: customized message string
 * Return: no of characters written
 */
int _write(char *buf, char *str, char *msg)
{	int len = 0, i = 0;

	for (; (buf[len] = str[i]) != '\0'; i++, len++)
		;
	for (i = 0; (buf[len] = msg[i]) != '\0'; len++, i++)
		;
	i = write(1, buf, len);
	return (i);
}

/**
 * _strlen - strlen()
 * @s: string whose length to return
 * Return: length of string
 */
int _strlen(char s[])
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * set_success - set success to true of false
 * @i: value to set success to
 * Return: Nothing
 */
void set_success(int i)
{
	success = i;
}

