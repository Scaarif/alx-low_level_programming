#include "main.h"
#include <stdio.h>

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

