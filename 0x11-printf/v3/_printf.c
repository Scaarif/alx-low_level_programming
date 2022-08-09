#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

/**
 * is_flag - check if character after % is a format
 * initializer or a flag
 * @arr: format arg of _printf
 * @i: identified possible 'format string' index
 * Return: int 1 if true and -1 otherwise
 */

int is_flag(const char *arr, int i)
{
	/*check if index contains a non-alphabet char, in which case that's a flag*/
	printf("@ is_flag\n");
	if ((arr[i] < 'a' || arr[i] > 'z') && (arr[i] < 'A' || arr[i] > 'Z'))
	{
		printf("indices[%d] is: %c a flag\n", i, arr[i]);
		return (i); /*true - return the flag's index*/
	}
	printf("NOT a flag!\n");
	return (-1);/*false otherwise*/
}

/**
 * get_flags - return index of actual format string
 * @arr: identified 'format strings' array
 * @ids: actual 'format strings' array
 * @fmt: _printf's required argument
 * Return: an array of flag indices
 */

int *get_flags(const char *fmt, int *arr, int *ids)
{
	int i = 1, j = 1, flags = 0, *f_arr, _next;

	/*check the array for flags and append them to the flags array*/
	while (arr[i])
	{
		if (is_flag(fmt, arr[i]) >= 0)
		{
			flags += ids[i] - arr[i];
			/*get other flags before actual specifier*/	
		}
		i++;
	}
	/*alloc mem & initialize an array of flags*/
	f_arr = malloc(sizeof(int) * (flags + 1));
	if (f_arr == NULL)
	{
		printf("f_arr failed");
		exit(99);
	}
	/*first value in f_arr = no of flags*/
	f_arr[0] = flags;
	i = 1;
	while (arr[i])
	{
		if (is_flag(fmt, arr[i]) >= 0)
		{
			f_arr[j] = arr[i];/*the index*/
			printf("flag[%d] - %c\n", j, fmt[arr[i]]);
			j++;
			/*add the other flags before actual f_str*/
			_next = arr[i] + 1;
			for (; _next < ids[i]; _next++, j++)
			{
				f_arr[j] = _next;
				printf("flag[%d] - %c\n", j, fmt[_next]);
			}
		}
		i++;
	}
	return (f_arr);
}

/**
 * actual_specifier - return index of actual format string
 * @fmt: _printf's required argument
 * @idx: flag's index
 * Return: index of actual specifier
 */

int actual_specifier(const char *fmt, int idx)
{

	/*check for specifier starting at identified flag's index*/
	while (fmt[idx])
	{
		idx++;
		/*check for first alphabet character after flag*/
		if ((fmt[idx] >= 'a' && fmt[idx] <= 'z') || (fmt[idx] >= 'A' && fmt[idx] <= 'Z'))
		{
				return (idx); /*true - return that first index - that's the f_str*/
		}
	}
	exit(99);
}

/**
 * get_actual_specifiers - return array of actual format strings
 * @arr: identified possible 'format strings' array
 * @fmt: first argument of _printf
 * Return: an array of actual indices
 */

int *get_actual_specifiers(const char *fmt, int *arr)
{
	int i = 1,j = 1, *a_arr;

	/*a_arr will have the same size as arr - in arr[0]*/
	a_arr = malloc(sizeof(int) * arr[0]);
	if (a_arr == NULL)
	{
		printf("a_arr failed");
		exit(99);
	}
	a_arr[0] = arr[0];
	/*else get the actual specifier, check that what we have isn't a flag*/
	while (arr[i])
	{
		if (is_flag(fmt, arr[i]) >= 0)
		{
			a_arr[j] = actual_specifier(fmt, arr[i]);
			printf("actual_indices[%d] @ %d is: %c\n", a_arr[j], j, fmt[a_arr[j]]);
		}
		else
		{
			a_arr[j] = arr[i];
			printf("retained_indices[%d] @ %d is: %c\n", a_arr[j], j, fmt[a_arr[j]]);
		}
		j++;
		i++;
	}
	return (a_arr);
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
	int j, k, flg, idx = 0, start = 0, stop = 0, last, chars = 0, *ids, *index;
	int alt_stop, *flags;
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

	};

	/*first case scenario, no optional args else*/
	index = get_indices(format);
	ids = get_actual_specifiers(format, index);
	flags = get_flags(format, index, ids);
	printf("flags: %d\n", flags[0]);/*the no of flags*/
	str[0] = 0;/*keep track of last appended to index*/
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
			stop = idx - 1;/*stop before the format string or flag is we have one*/
			alt_stop = index[k] - 1;
			if (stop > alt_stop)
			{
				stop = alt_stop;/*stop at first occurrence of some sort of a specifier*/
			}
			printf("Start[%d]: %d\n", k, start);
			printf("Stop[%d]: %d\n", k, stop);
			/*print string before the format string*/
			chars += print_string(format, start, stop, str);
			flg = alt_stop + 1;/*idx of first flag in current batch*/
			/*if (flags[flg] < idx)*/
			/*{*/
				/*determine what to do based on flag character*/
				/*chars += handle_flag(format[flags[k]], str);
			}*/
			/*loop through the options looking for the right fn to call*/
			for (; flg < idx; flg++)
				chars += handle_flag(format[flg], str);
			j = 0; /* no of fns available */
			while (j < 11)
			{
				if (*(options[j].s) == format[idx])
				{
					chars += options[j].f(ap, str);
					/*update start*/
					start = idx + 1;
					printf("\nStart[%d]: %d\n", k + 1, start);
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
		/*printf("last_start: %d at char %c and last: %d at char %c, alas!\n", start, format[start], last, format[last]);*/
		chars += print_string(format, start, last, str);
		return (chars);
		
	}
	/*else return default/first case scenario: print the string*/
	return(print_string(format, start, strlen(format), str));
}

