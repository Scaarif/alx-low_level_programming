#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include "main.h"

/**
 *_num - returns number of characters in an int
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

void _print_num(long n, ...)
{
	va_list ap;
	char *str;
	int num;

	if ((n / 10) > 0)
	{
		_print_num(n / 10);
	}
	num = '0' + (n % 10);
	write(1, &num, 1);
	va_start(ap, n);
	str = va_arg(ap, char *);
	/*printf("_num:%i - %c\n", _num, _num);*/
	manage_buffer_with_pointers(str, num);
	va_end(ap);

}

/**
 * print_int - writes a int to stdout, 1
 * @arg: int to write - an optional argument
 * Return: int number of bytes written
 */
int print_int(va_list arg, ...)
{
	va_list ap;
	int n = 0, num, last_index, num_len, f_index, idx, i = 0;
	char neg, *str, *fmt, *p_flags;
	long min;

	num = va_arg(arg, int);
	va_start(ap, arg);
	str = va_arg(ap, char *);
	fmt = va_arg(ap, char *);
	f_index = va_arg(ap, int);
	idx = va_arg(ap, int);
	p_flags = va_arg(ap, char *);

	/*check if num is negative*/
	if (num < 0)
	{
		neg = '-';
		n += write(1, &neg, 1);
		/*check last char in str, if + replace it;*/
		last_index = str[0];
		if (str[last_index] == '+' || str[last_index] == ' ' ||
		str[last_index] == '#' || str[last_index] == '0')
		{
			str[0] -= 1;
			/*printf("Removed a + or [space]!\n");*/
		}
		manage_buffer_with_pointers(str, neg);
		last_index = str[0];
		/*printf("updated_last_index: %d with: %c\n", str[0], str[last_index]);*/
		num *= -1;
	}
	else
	{
		for (; f_index < idx; f_index++)
		{
			for (; i < 5; i++)
			{
				if (fmt[f_index] == p_flags[i])
					n += write(1, fmt + f_index, 1);
			}
		}
	}
	if (num == INT_MIN)
	{
		min = (long)num * -1;
		_print_num(min, str);
		num_len = _num(min);
	}
	else
	{
		num_len = _num((long)num);
		_print_num((long)num, str);
	}
	n += num_len;
	return (n);
}


/**
 * print_binary - converts unsigned int to binary
 * @arg: the integer to turn into binary
 * Return: int number of characters written
 */

int print_binary(va_list arg, ...)
{
	int num, i, k, start = 32, len = 0;
	char bytes[BUFFER], *zero = "00";

	num = va_arg(arg, int);
	/*assuming size of 32 max bits*/
	for (i = 31; i >= 0; i--)
	{
		k = num >> i; /*right shift*/
		if (k & 1)
		{
			bytes[i] = '1';
		}
		else
		{
			bytes[i] = '0';
		}
	}
	for (i = 31; i >= 0; i--)
	{
		if (bytes[i] == '1')
		{
			start = i;
			break;
		}
	}
	/*printf("start: %d with %c\n", start, bytes[start]);*/
	if (start == 32)/*we have all zeros*/
	{
		len += 2;
		write(1, zero, 2);
	}
	else
	{
		for (i = start; i >= 0; i--)
		{
			len++;
			write(1, bytes + i, 1);
		}
	}
	return (len);
}

/**
 * make_unsigned - converts unsigned int to unsigned
 * @arg: the integer to turn into binary
 * Return: int number of characters written
 */

int make_unsigned(va_list arg, ...)
{
	int n = 0;
	long num;

	num = va_arg(arg, long);
	if (num < 0)
		num = 4294967296 + num;
	/*print the number & get no of chars written*/
	_print_num(num);
	n += _num(num);/*count no of chars in the int*/
	return (n);
}
