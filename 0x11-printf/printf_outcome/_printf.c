#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

/**
 * actually_print - writes to stdout, 1
 * @format: only required argument
 * @index: array of possible format strings, indices
 * @ids: array of actual format strings, indices
 * @options: array of structures, f_str and functions
 * @str: buffer
 * @ap: va_list
 * Description: format is a string and contains
 * the optional format strings
 * Return: int number of bytes written
 */
int actually_print(const char *format, int *index, int *ids, fn *options,
char *str, va_list ap)
{
	int j, k, flg, idx = 0, start = 0, stop = 0, chars = 0, alt_stop;
	char *p_flags = "+-# 0"; /*before 0 is space; len = 5*/

	/*printf("evaluating actually_print\n");*/
	k = 1; /*ids[0] is the array_size*/
	/*loop through indices(ids)*/
	while (k <= ids[0])
	{
		idx = ids[k];
		stop = idx - 1;/*stop before the format string or flag is we have one*/
		alt_stop = index[k] - 1;
		if (stop > alt_stop)
		{
			stop = alt_stop;/*stop at first occurrence of some sort of a specifier*/
		}
		/**
		 * printf("Start[%d]: %d\n", k, start);
		 * printf("Stop[%d]: %d\n", k, stop);
		 */
		/*print string before the format string*/
		chars += print_string(format, start, stop, str);
		flg = alt_stop + 1;/*idx of first flag in current batch*/
		for (; flg < idx; flg++)
			chars += handle_flag(format[flg], str);
		j = 0; /* no of fns available */
		while (j < 13)
		{
			if (*(options[j].s) == format[idx])
			{
				chars += options[j].f(ap, str, format, index[k], idx, p_flags);
				/*update start*/
				start = idx + 1;
				/*printf("\nStart[%d]: %d\n", k + 1, start);*/
			}
			j++;
		}
		k++;
	}
	return (chars);
}
/**
 * _printf - writes to stdout, 1
 * @format: only required argument
 * Description: format is a string and contains
 * the optional format strings
 * Return: int number of bytes written
 */
int _printf(const char *format, ...)
{
	int start = 0, last, chars = 0, *ids, *index, last_fs_idx, last_start;
	char str[BUFFER];/*hold what i want to print*/
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
		{"r", print_reverse_string},
		{"R", rot13},
	};

	index = get_indices(format);
	ids = get_actual_specifiers(format, index);
	/*flags = get_flags(format, index, ids);*/
	str[0] = 0;/*keep track of last appended to index*/
	if (ids[0])
	{
		/*printf("no of f_strs: %d\n", ids[0]);*/
		last_fs_idx = ids[0];
		last_start = ids[last_fs_idx] + 1;
		va_start(ap, format);
		/*loop through indices(ids) - call actually_print*/
		chars += actually_print(format, index, ids, options, str, ap);
		va_end(ap);
		last = _strlen((char *)format);/*last part of string*/
		chars += print_string(format, last_start, last, str);
		return (chars);
	}
	return (print_string(format, start, _strlen((char *)format), str));
}

