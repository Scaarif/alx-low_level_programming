#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

#define BUFFER 32

/**
 * get_bit - returns the value of bit at a given index
 * @n: the unsigned long integer
 * @index: the index at which to return a bit
 * Return: the value of bit or -1 if an error occurs
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int num, k;
	int _start = 0, i, j;
	char bytes[BUFFER], *zero = "0";

	num = n;
	/*assuming size of 32 max bits*/
	for (i = 31; i >= 0 && num; i--)
	{
		k = num >> i; /*right shift which is in essence dividing*/
		if (k & 1)
		{
			bytes[i] = '1';
			if (_start == 0)
				_start = i;
		}
		else
		{
			bytes[i] = '0';
		}
	}
	if (_start == 0 && num != 1)/*we have all zeros*/
	{
		bytes[0] = *zero;
	}
	/*in reality, we have start + 1 bytes since start is inclusive*/
	j = _start + 1;
	bytes[j] = j;/*keep track of no of bits - not necessary though*/
	j = _start;
	if ((int)index >= 0 && j >= (int)index)
	{
		for (; j >= 0; j--)
		{
			if (j == (int)index)
				return (bytes[j] - '0');
		}
	}
	return (-1);
}
