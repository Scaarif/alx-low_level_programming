#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 *
 * Description: print the alphabet using putchar()
 *
 * Return: Always 0 (Success)
 *
 */

int main(void)
{
	char x = 'a';

	while (x <= 'z')
	{
		if (x == 'e' || x == 'q')
		{
			x++;
		}
		else
		{
			putchar(x);
			x++;
		}
	}
	putchar(10);
	return (0);
}
