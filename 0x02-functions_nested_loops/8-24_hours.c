#include "main.h"

/**
 * jack_bauer - print each minute in 24 hours
 * Description: takes no arguments and has no return value
 * :starts at 00:00 and ends 23:59
 * Return: void
 */

void jack_bauer(void)
{
	int h = 0;

	while (h < 24)
	{
		int first = h / 10;
		int second = h % 10;
		int m = 0;

		while (m < 60)
		{
			int third = m / 10;
			int forth = m % 10;

			_putchar(first + '0');
			_putchar(second + '0');
			_putchar(':');
			_putchar(third + '0');
			_putchar(forth + '0');
			_putchar('\n');
			m++;
		}
		h++;
	}
}