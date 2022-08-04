#include "variadic_functions.h"
#include <stdio.h>
#include <string.h>

/**
 * print_string - prints a string
 * @arg: the string to print
 * Return: Nothing
 */
void print_string(va_list arg)
{
	char *str;

	str = va_arg(arg, char *);
	if (str == NULL)
		str = "(nil)";
	printf("%s", str);
}

/**
 * print_char - prints a char
 * @arg: the char to print
 * Return: Nothing
 */
void print_char(va_list arg)
{
	printf("%c", va_arg(arg, int));
}

/**
 * print_int - prints an int
 * @arg: the int to print
 * Return: Nothing
 */
void print_int(va_list arg)
{
	printf("%d", va_arg(arg, int));
}

/**
 * print_float - prints a float
 * @arg: the float to print
 * Return: Nothing
 */
void print_float(va_list arg)
{
	printf("%f", va_arg(arg, double));
}

/**
 * print_all - prints anything
 * @format: arguments format say cis for
 * char, int , string (char *)
 * Return: Nothing
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	int i = 0, j, len;
	the_func fs[] = {
		{'c', print_char},
		{'i', print_int},
		{'f', print_float},
		{'s', print_string},
	};

	/*initialize the arguments list*/
	va_start(ap, format);
	/*loop through format string to choose correct function*/
	len = (int)strlen(format);
	while (i < len)
	{
		j = 0;
		while (j < 4)
		{
			if (fs[j].format_str == format[i])
			{
				fs[j].f(ap);/*call app. fn*/
				/*printf("%c's fn called\n", fs[j].format_str);*/
			}
			j++;
		}
		if (i < len - 2)
			printf(", ");
		i++;
	}
	printf("\n");
	va_end(ap);
}


