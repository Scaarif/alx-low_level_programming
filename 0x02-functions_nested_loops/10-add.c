#include "main.h"
#include <unistd.h>
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
	printf("%d\n", add(109, 19));
	printf("%d\n", add(4, 8));
	return (0);
}

/**
 * add - returns sum of two numbers
 * @i: argument int i
 * @j: argument int j
 * Description: takes two numbers as arguments and returns their sum
 * Return: sum of numbers
 */

int add(int i, int j)
{
	int res = i + j;

	return (res);
}

int _putchar(char c)
{
	return (write(1, &c, 1));
}

