#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/**
 * print_int - writes a int to stdout, 1
 * @arg: int to write - an optional argument
 * Return: int number of bytes written
 */
int print_int(va_list arg)
{
	int n, num;

	num = va_arg(arg, int);
	n = write(1, &num, 1)
	return(n);
}


