#include <stdarg.h>
#include "variadic_functions.h"

/**
 * sum_them_all - sums all its parameters
 * @n: number of parameters
 * Return: int sum
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list ap;
	int sum = 0;
	unsigned int i = 0;

	if (n == 0)
		return (sum);
	/*initialize the arguments list*/
	va_start(ap, n);
	/*get the next argument, sequentially*/
	for (; i < n; i++)
		sum += va_arg(ap, int); /*int: type of optional arg*/
	/*clear ap before fn return*/
	va_end(ap);
	return (sum);
}
