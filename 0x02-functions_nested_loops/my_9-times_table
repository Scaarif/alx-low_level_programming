#include "main.h"

/**
 * times_table - print the times table
 * Description: takes no arguments and has no return value
 * Return: void
 */

void times_table(void)
{
	int i = 0;

	while (i < 10)
	{
		int m = 0;

		while (m < 10)
		{
			int result = i * m;

			if (i == 0)
			{
				_putchar(i + '0');
			}
			else if (i == 1)
			{
				_putchar(m + '0');
			}
			else
			{
				if (result > 9)
				{
					_putchar((result / 10) + '0');
					_putchar((result % 10) + '0');
				}
				else
				{
					_putchar(result + '0');
				}
			}
			_putchar(',');
			if (result <= 9)
				_putchar(' ');
			_putchar(' ');
			m++;
		}
		_putchar('\n');
		i++;
	}
}

