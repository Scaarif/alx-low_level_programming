#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

/**
 * manage_buffer - keep track of characters to be printed
 * @fmt: format argument of _printf
 * @str: the buffer at current state
 * @start: int index
 * @stop: int index
 * Return: the buffer
 */
char *manage_buffer(const char *fmt, char *str, int start, int stop)
{
	int count = str[0] + 1;

	for (; count < BUFFER && start < stop; count++, start++)
		str[count] = fmt[start];
	/*update str[0] at the end*/
	str[0] = count - 1;/* or is it - 2?*/
	/**
	 * printf("\nStr: ");
	 * for (; i <= str[0]; i++)
	 * printf("%c", *(str + i));
	 * printf("\n");
	 */
	return (str);
}


/**
 * manage_buffer_with_pointers - keep track of characters to be printed
 * @str: the buffer at current state
 * @c: character to append to str
 * Return: the buffer
 */
char *manage_buffer_with_pointers(char *str, char c)
{
	int count = str[0] + 1, stop = count + 1;

	for (; count < stop; count++)
	{
		str[count] = c;
		/*printf("i.e.: %c", *(str + count));*/
	}
	/*update str[0] at the end*/
	str[0] = count - 1;/* or is it - 2?*/
	/**
	 * printf("\npointer_Str: ");
	 * for (; i <= str[0]; i++)
	 * printf("%c", *(str + i));
	 * printf("\n");
	 */
	return (str);
}

/**
 * get_width - returns the filed width specifier
 * @fmt: buffer
 * @idx: index of last character in str(fmt)
 * Return: the width
 */
int get_width(char *fmt, int idx)
{
	int width = 0;

	if (fmt[idx] == '-')
		idx--;
	/*printf("last char: %c\n", fmt[idx]);*/
	for (; fmt[idx] == '*'; idx--, width++)
		;
	return (width);
}

/**
 * _strlen - returns length of a string
 * @s: string
 * Return: int
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}

/**
 * _power - returns the y power of x
 * @x: integer one
 * @y: integer two
 * Return: integer power
 */

int _power(int x, int y)
{
	int pow;

	if (y < 0)
	{
		pow = -1;
	}
	else if (y == 0)
		pow = 1;
	else if (y == 1)
		pow = x;
	else
	{
		pow = x * _power(x, y - 1);
	}
	return (pow);
}
