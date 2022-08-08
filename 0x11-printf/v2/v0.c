#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _print_num - returns number of characters in an int
 * @n: the integer
 * Return: int number of characters
 */

int _num(long n)
{
	int num = 1;

	for (; (n / 10) > 0; num++)
	{
		n = n / 10;
	}
	return (num);
}
/**
 * _print_num - prints an int as a character
 * @n: the integer
 * Return: int number of bytes written
 */

void _print_num(long n)
{
	int num;

	if ((n / 10) > 0)
	{
		_print_num(n / 10);
	}
	num = '0' + (n % 10);
	write(1, &num, 1);
}

/**
 * print_int - writes a int to stdout, 1
 * @arg: int to write - an optional argument
 * Return: int number of bytes written
 */
int print_int(va_list arg)
{
	int n = 0, num;
	char neg;

	/*think I need to int to convert to char (ascii)?*/
	num = va_arg(arg, int);
	/*check if num is negative*/
	if (num < 0)
	{
		neg = '-';
		n += write(1, &neg, 1);
		num *= -1;
	}
	/*printf("num: %d\n", num);*/
	_print_num((long)num);
	n += _num((long)num);
	return(n);
}


/**
 * print_binary - converts unsigned int to binary
 * @arg: the integer to turn into binary
 * Return: int number of characters written
 */

int print_binary(va_list arg)
{
	int num, n = 0, i, k;
	char c;

	num = va_arg(arg, int);
	/*assuming size of 32 bits*/
	for (i = 7; i >= 0; i--)
	{
		k = num >> i; /*right shift*/
		if (k & 1)
		{
			c = '1';
			n += write(1, &c, 1);
		}
		else
		{
			c = '0';
			n += write(1, &c, 1);
		}
	}
	return (n);
}

/**
 * make_unsigned - converts unsigned int to unsigned
 * @arg: the integer to turn into binary
 * Return: int number of characters written
 */

int make_unsigned(va_list arg)
{
	int n = 0;
	long num;

	num = va_arg(arg, long);
	if (num < 0)
		num = 4294967296 + num;
	/*print the number & get no of chars written*/
	/*printf("num: %ld\n", num);*/
	_print_num(num);
	n += _num(num);/*count no of chars in the int*/
	return (n);
}