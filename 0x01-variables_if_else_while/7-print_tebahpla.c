#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 *
 * Description: print the alphabet using putchar() in reverse
 *
 * Return: Always 0 (Success)
 *
 */

int main(void)
{
	char x = 'z';
	
	while (x >= 'a')
	{
		putchar(x);
		x--;
	}
	putchar(10);
	return (0);
}
