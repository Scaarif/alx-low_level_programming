#include "main.h"

/**
 * main - entry point
 *
 * Description: calls the _isalpha and _putchar functions
 *
 * Return: always 0
 *
 */
int main(void)
{
	_isalpha('c');
	_isalpha('H');
	_isalpha(108);
	_putchar('\n');
	return (0);
}

/**
 * _isalpha - check if a char is alphabet
 * @c: only argument
 * Description: takes one int argument and has no return an int
 * Return: 1 or 0 for true and false
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		_putchar('1');
		return (1);
	}
	else
	{
		_putchar('0');
		return (0);
	}
}


