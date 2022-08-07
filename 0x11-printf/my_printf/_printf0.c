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
	indices = malloc(sizeof(int) * ids);
	if (indices == NULL)
	{
		printf("indices: failed");
		exit(99);
	}
	else
	{
		/*initialize the array with the indices*/
		printf("indices mem allocated\n");
		i = 0;
		while (i < ids)
		{
			/*i need to call is_specifier ids times*/
			_is = is_specifier(str, start);
			printf("start: %d and _is: %d\n", start, _is);
			printf("indices[%d]: %d\n", i, _is);
			indices[i] = str[_is];
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
		printf("start: 0\n");
	}
	else
	{
		len = (stop - start) + 1;
	}
	/*printf("len: %d\n", len);*/
	n = write(1, s, len);
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
	int j, idx = 0, start = 0, stop, *ids;
	va_list ap;
	fn options[] = {
		{"s", print_str},
		{"c", print_char},
	};

	/*first case scenario, no optional args else*/
	ids = get_indices(format);
	j = 0;
	while(ids[j])
	{
		printf("format string: %c\n", ids[j]);
		j++;
	}
	idx = is_specifier(format, idx);
	printf("idx: %d\n", idx);
	stop = idx;
	if (idx)
	{
		/*look at the specifier(at (idx + 1)th index, print the next optional arg*/
		va_start(ap, format);
		/*loop through the options looking for the right fn to call*/
		j = 0; /* no of fns available */
		while (j < 2)
		{
			if (*(options[j].s) == format[idx])
			{
				/*print string before the format string*/
				print_string(format, start, stop);
				/*printf("\n");*/
				return(options[j].f(ap));
				/*update start*/
				start = idx + 2;
			}
			j++;
		}
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
	len = _printf("Ra%c %s %s\n", 'H', "Scaarif", "Ngache");
	/*len = print_string("Let's try to printf a simple sentence.\n");*/
	/*len2 = printf("Let's try to printf a simple sentence.\n");*/
	/* printf("len: %d, len2: %d strlen: %ld\n", len, len2, strlen(str));*/
	printf("len: %d\n", len);
	return (0);
}
