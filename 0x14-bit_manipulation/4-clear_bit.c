#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

#define BUFFER 33


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
		num += (b[i] - '0') * power(2, j);
		/*printf("num: %u\n", num);*/
	}
	return (num);
}

/**
 * clear_bit - sets the value of a bit at a given index to 0
 * @n: pointer to unsigned long integer
 * @index: the index at which to return a bit, starts at 0
 * Return: 1 if successful and -1 if an error occurs
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int num = *n, k;
	int i, j;
	char bytes[BUFFER], *binary;

	for (i = 31; i >= 0; i--)
	{
		k = num >> i; /*right shift which is in essence dividing*/
		if (k & 1)
		{
			bytes[i] = '1';
		}
		else
		{
			bytes[i] = '0';
		}
	}
	binary = malloc(sizeof(char) * 33);
	j = 31;
	if (j >= (int)index && binary)
	{
		for (; j >= 0; j--)
		{
			if (j == (int)index)
				bytes[j] = '0';/*set bit value*/
		}
		j = 0;
		for (i = 31; i >= 0; i--, j++)
			binary[j] = bytes[i];
		binary[j] = '\0';
		*n = binary_to_uint(binary);
		return (1);
	}
	return (-1);
}
