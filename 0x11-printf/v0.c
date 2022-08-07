#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

/**
 * _print_num - returns number of characters in an int
 * @n: the integer
 * Return: int number of characters
 */

int _num(int n)
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

void _print_num(int n)
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
	int n, num;

	/*think I need to int to convert to char (ascii)?*/
	num = va_arg(arg, int);
	/*start with single char int*/
	_print_num(num);
	n = _num(num);
	/*a_num = '0' + num;*/
	/*n = write(1, &a_num, 1);*/
	return(n);
}
