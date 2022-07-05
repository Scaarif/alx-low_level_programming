#include "main.h"
#include <unistd.h>
#include <stdio.h>
/**
 * main - entry point
 *
 * Description: calls the print_sign and _putchar functions as tests
 *
 * Return: always 0
 *
 */
int main(void)
{
	printf("%d\n", print_last_digit(109));
	printf("%d\n", print_last_digit(4));
	return (0);
}

/**
 * print_last_digit - prints last digit of a number
 * @n: only argument
 * Description: returns the last digit in the argument provided
 * Return: last digit
 */

int print_last_digit(int n)
{
	int last = n % 10;

	return (last);
}

int _putchar(char c)
{
	return (write(1, &c, 1));
}

