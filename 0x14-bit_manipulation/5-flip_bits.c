#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

#define BUFFER 33

/**
 * get_binary - converts a int number to binary
 * @n: integer to convert
 * @buff: empty buffer
 * Return: converted binary as string
 */
char *get_binary(unsigned long int n, char *buff)
{
	int i;
	unsigned long int num = n, k;

	/*printf("num: %lu\n", num);*/
	for (i = 31; i >= 0; i--)
	{
		k = num >> i; /*right shift which is in essence dividing*/
		if (k & 1)
		{
			buff[i] = '1';
		}
		else
		{
			buff[i] = '0';
		}
	}
	return (buff);
}

/**
 * flip_bits - returns the number of bits one needs to
 * flip to get from int n to int m
 * @n: int 1
 * @m: int 2
 * Return: number of bits fliped
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, j, count = 0;
	char bin[BUFFER], *_bin1, *_bin2, bin1[BUFFER], bin2[BUFFER];

	if (n && m)
	{
		_bin1 = get_binary(n, bin);
		/*this next part is not necessary*/
		for (i = 31, j = 0; i >= 0; i--, j++)
			bin1[j] = _bin1[i];
		_bin2 = get_binary(m, bin);
		for (i = 31, j = 0; i >= 0; i--, j++)
			bin2[j] = _bin2[i];
		for (i = 0, j = 0; i < 32 && j < 32; i++, j++)
		if (bin1[i] ^ bin2[j])
			count++;
	}
	return ((unsigned int)count);
}

