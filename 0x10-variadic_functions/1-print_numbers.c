#include <stdarg.h>
#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_numbers - prints numbers
 * and a new line at the end
 * @n: number of parameters (numbers)
 * @separator: the numbers separating string
 * Return: Nothing
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	unsigned int i = 0;

	if (n != 0)
	{
		/*initialize the arguments list*/
		va_start(ap, n);
		/*get the next argument, sequentially to print*/
		for (; i < n; i++)
		{
			printf("%d", va_arg(ap, int));
			if (separator != NULL)
				printf("%s", separator);
		}
		/*clear ap before fn return*/
		va_end(ap);
	}
	/*print the new line*/
	printf("\n");
}

