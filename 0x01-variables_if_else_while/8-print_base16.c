#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 *
 * Description: print the numbers of base 16 using putchar()
 *
 * Return: Always 0 (Success)
 *
 */

int main(void)
{
	char x = 'a';
	int i = 48;
	int j = 48 + 9;
	
	while (i <= j)
	{
		putchar(i);
		i++;
	}
	while (x <= 'f')
	{
		putchar(x);
		x++;
	}
	putchar(10);
	return (0);
}
