#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct specifier
{
	char *s;
	int (*f)();/*optional args?*/
} fn;

/**
 * is_specifier - check if % is a format
 * initializer
 * @str: printf's first argument
 * Return: int 1 if true and -1 otherwise
 */

int is_specifier(const char *str, int index)
{
	int i = index;/*where to start next search for specifier*/

	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] != '%')
				return (i + 1); /*true - return the specifier's index*/
		}
		i++;
	}
	index  = 0;
	return (index);/*false*/
}

int *get_indices(const char *str)
{
	int i = 0, ids = 0, _is, start = 0, *indices;

	/*find out how many specifiers there are;*/
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] != '%')
				ids++;
		}
		i++;
	}
	printf("no of format strings: %d\n", ids);
	/*allocate memory to the array and initialize*/
	indices = malloc(sizeof(int) * (ids + 1));
	if (indices == NULL)
	{
		printf("indices: failed");
		exit(99);
	}
	else
	{
		/*initialize the array with the indices*/
		printf("indices mem allocated\n");
		indices[0] = ids;/*array_size*/
		i = 1;
		while (i <= ids)
		{
			/*i need to call is_specifier ids times*/
			_is = is_specifier(str, start);
			printf("start: %d and _is: %d\n", start, _is);
			printf("indices[%d]: %d\n", i, _is);
			/*indices[i] = str[_is];*/
			indices[i] = _is;/*store the index not the char at the index*/
			/*printf("indices[%i]: %d", i, indices[i]);*/
			start = _is + 1;
			i++;
		}
	}
	return (indices);
}

int print_string(const char *s, int start, int stop)/*whatever value is pointed to is constant*/
{
	int n, len;

	if (start == 0)
	{
		len = stop - start;
		/*printf("start: 0\n");*/
	}
	else
	{
		len = (stop - start) + 1;
	}
	/*printf("len: %d\n", len);*/
	n = write(1, s + start, len);
	return(n);
}

int print_str(va_list arg)
{
	int n;
	char *s;

	s = va_arg(arg, char *);
	n = write(1, s, strlen(s));
	return(n);
}


int print_char(va_list arg)
{
	int n;
	char s;

	s = va_arg(arg, int);
	n = write(1, &s, 1);
	return(n);
}

/**
 * int actual_print(char *format, int start, int stop)
 * {
 * return (0);
 * }
 */

int _printf(const char *format, ...)
{
	int j, k, idx = 0, start = 0, stop = 0, last, chars = 0, *ids;
	va_list ap;
	fn options[] = {
		{"s", print_str},
		{"c", print_char},
	};

	/*first case scenario, no optional args else*/
	ids = get_indices(format);
	j = 1;
	if (ids[0])
	{
		printf("evaluating inner conditional\n");
		k = 1; /*ids[0] is the array_size*/
		/*loop through indices(ids)*/
		while (k <= ids[0])
		{
			/*idx = is_specifier(format, idx);*/
			idx = ids[k];
			printf("the idx: %d\n", idx);
			stop = idx - 1;/*stop before the format string*/
			/*look at the specifier(at (idx + 1)th index, print the next optional arg*/
			va_start(ap, format);
			/*print string before the format string*/
			print_string(format, start, stop);
			/*loop through the options looking for the right fn to call*/
			j = 0; /* no of fns available */
			while (j < 2)
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
		/*for the last part of string(after last format string)*/
		last = strlen(format) - 1;
		/*printf("last_start: %d\n", start);*/
		chars += print_string(format, start, last);
		return (chars);
		
	}
	/*else return default/first case scenario: print the string*/
	return(print_string(format, start, strlen(format)));
}


int main(void)
{
	int len;
	/*unsigned int ui;*/
	/*void *addr;*/

	printf("output from _printf:\n");
	len = _printf("Ra%cab\n", 'H');
	/*len = print_string("Let's try to printf a simple sentence.\n");*/
	/*len2 = printf("Let's try to printf a simple sentence.\n");*/
	/* printf("len: %d, len2: %d strlen: %ld\n", len, len2, strlen(str));*/
	printf("len: %d\n", len);
	return (0);
}
