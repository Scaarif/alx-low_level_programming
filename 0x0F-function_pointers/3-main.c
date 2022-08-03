#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - check the functions
 * @argc: integer number of arguments passed
 * @argv: array of string arguments passed on call
 * Return: int 0 if success, 98 if argc != 4, 99 if operator
 * is wrong and 100 if zero-division is involved
 */

int main(int argc, char **argv)
{
	int (*op_fn)(int, int), num1, num2, result;
	/*check number of args*/
	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}
	/*select fn to run - op = argv[2]*/
	op_fn = get_op_func(argv[2]);
	if (op_fn == NULL)
	{
		printf("Error\n");
		exit(99);
	}
	/*get the two nums: argv[1] and argv[3]*/
	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);
	/*operate on the numbers and print result*/
	result = op_fn(num1, num2);
	printf("%d\n", result);
	exit(0);
}
