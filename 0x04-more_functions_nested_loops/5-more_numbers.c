#include "main.h"

/**
 * more_numbers - print numbers 0 to 9
 * Description: takes no arguments
 * Return: void
 */

void more_numbers(void)
{
	int i = 0;

	while (i < 10)
	{
		int a = 0;

		while (a <= 14)
		{
			if (a > 9)
				_putchar((a / 10) + '0');
			_putchar((a % 10) + '0');
			a++;
		}
		_putchar('\n');
		i++;
	}
}
