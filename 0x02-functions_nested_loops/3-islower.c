#include "main.h"

/**
 * main - entry point
 *
 * Description: calls the _islower and _putchar functions
 *
 * Return: always 0
 *
 */
int main(void)
{
	_islower('c');
	_islower('H');
	_islower(106);
	_putchar('\n');
	return (0);
}

/**
 * _islower - check if a char is lowercase
 * @c: only argument
 * Description: takes one int argument and has no return an int
 * Return: 1 or 0 for true and false
 */

int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
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


