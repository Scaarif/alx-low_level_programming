#include <stdarg.h>
#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_strings - print strings
 * and a new line at the end
 * @n: number of parameters (strings)
 * @separator: the string separating string
 * Return: Nothing
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	unsigned int i;
	char *str;

	if (n != 0)
	{
		/*initialize the arguments list*/
		va_start(ap, n);
		/*get the next argument, sequentially to print*/
		for (i = 0; i < n; i++)
		{
			/*get the next string first:*/
			str = va_arg(ap, char *);
			printf("%s", (str == NULL) ? "(nil)" : str);
			if (separator != NULL)
				printf("%s", separator);
		}
		/*clear ap before fn return*/
		va_end(ap);
	}
	/*print the new line*/
	printf("\n");
}

