#include <stdio.h>
#include <stdlib.h>
/**
 * main - entry point
 *
 * Description: print the alphabet using putchar()
 *
 * Return: always 0 (success)
 *
 */

int main(void)
{
	char x = 'a';

	while (x <= 'z')
	{
		putchar(x);
		x++;
	}
	putchar(10);
	return (0);

}
