#include "main.h"
#include <stdio.h>

/**
 * print_rev_recursion - prints a string in reverse
 * @s: string
 * Return: nothing
 */

void _print_rev_recursion(char *s)
{
	if (*s == '\0')
		return;

	_print_rev_recursion(s + 1);
	/* printf("\np: %p\n", s); */
	_putchar(*s);
}

