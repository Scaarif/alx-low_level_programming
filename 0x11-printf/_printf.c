#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/**
 * _printf - writes to stdout, 1
 * @format: only required argument
 * Description: format is a string and contains
 * the optional format strings
 * Return: int number of bytes written
 */
int _printf(const char *format, ...)
{
	int j, k, idx = 0, start = 0, stop = 0, last, chars = 0, *ids;
	va_list ap;
	fn options[] = {
		{"s", print_str},
		{"c", print_char},
		{"b", print_binary},
		{"d", print_int},
		{"i", print_int},
		{"u", make_unsigned},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_heX},
		{"S", print_Str},
		{"p", print_pointer},

	};

	/*first case scenario, no optional args else*/
	ids = get_indices(format);
	j = 1;
	if (ids[0])
	{
		printf("evaluating inner conditional\n");
		k = 1; /*ids[0] is the array_size*/
		/*look at the specifier(at (idx + 1)th index, print the next optional arg*/
		va_start(ap, format);
		/*loop through indices(ids)*/
		while (k <= ids[0])
		{
			/*idx = is_specifier(format, idx);*/
			idx = ids[k];
			/*printf("the idx: %d\n", idx);*/
			stop = idx - 1;/*stop before the format string*/
			/*print string before the format string*/
			chars += print_string(format, start, stop);
			/*loop through the options looking for the right fn to call*/
			j = 0; /* no of fns available */
			while (j < 11)
			{
				if (*(options[j].s) == format[idx])
				{
					chars += options[j].f(ap);
					/*update start*/
					start = idx + 1;
				}
				j++;
			}
			k++;
			/*printf("k: %d\n", k);*/
			/*print rest of string after f.s happens next time in the loop*/
		}
		va_end(ap);
		/*for the last part of string(after last format string)*/
		last = strlen(format);
		/*printf("last_start: %d at char %c and last: %c\n", start, format[start], format[last]);*/
		chars += print_string(format, start, last);
		return (chars);
		
	}
	/*else return default/first case scenario: print the string*/
	return(print_string(format, start, strlen(format)));
}

