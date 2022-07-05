#include "main.h"
#include <stdio.h>
/**
 * main - entry point
 *
 * Description: calls the add and _putchar functions as tests
 *
 * Return: always 0
 *
 */
int main(void)
{
	print_to_98(102);
	print_to_98(72);
	print_to_98(98);
	return (0);
}

/**
 *print_to_98 - print to 98
 * @i: argument int i, only argument
 * Description: prints to 98 starting with the argument received, in order
 * Return: void
 */

void print_to_98(int i)
{
	if (i < 98)
	{
		while (i < 98)
		{
			printf("%d, ", i);
			i++;
		}
	}
	else if (i > 98)
	{
		while (i > 98)
		{
			printf("%d, ", i);
			i--;
		}
	}
	printf("%d", i);
	printf("\n");
}

