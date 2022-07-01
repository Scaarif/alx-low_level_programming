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
	char X = 'A';

	while (x <= 'z')
	{
		putchar(x);
		x++;
	}
	while (X <= 'Z')
	{
		putchar(X);
		X++;
	}
	putchar(10);
	return (0);
}
