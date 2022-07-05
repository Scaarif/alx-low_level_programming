#include "main.h"

/**
 * times_table - print the times table
 *@k: single argument
 * Description: takes one argument and has no return value
 * Return: void
 */

void print_times_table(int k)
{
	int i = 0;

	while (i <= k)
	{
		int m = 0;

		while (m <= k)
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
				if (result > 9 && result < 100)
				{
					_putchar((result / 10) + '0');
					_putchar((result % 10) + '0');
				}
				else if (result > 99)
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


