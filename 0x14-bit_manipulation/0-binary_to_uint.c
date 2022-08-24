#include "main.h"
#include <stddef.h>
#include <stdio.h>

/**
 * power - returns the power of 2 integers
 * @a: int 1
 * @b: int 2
 * Return: the unsigned int power/result
 */
unsigned int power(int a, int b)
{
	int pow;

	if (b < 0)
		pow = -1;
	else if (b == 0)
		pow = 1;
	else if (b == 1)
		pow = a;
	else
		pow = a * power(a, b - 1);
	return ((unsigned int)pow);
}

/**
 * binary_to_uint - converts a bibary number to an unsigned int
 * @b: the binary number string
 * Return: converted unsigned integer
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0;
	int j = 0, i;

	if (b == NULL)
		return (0);
	for (i = 0; b[i] != '\0'; i++)
	{
		if (!(b[i] == '0' || b[i] == '1'))
		{
			/*printf("char: %c\n", b[i]);*/
			return (0);
		}
	}
	/*i = strlen*/
	for (i--; i >= 0; i--, j++)
	{
		/*printf("char_int: %d\n", b[i] - '0');*/
		/*num += (b[i] - '0') * power(2, j);*/
		num += (b[i] - '0') << j; /*same thing as above*/
		/*printf("num: %u\n", num);*/
	}
	return (num);
}
