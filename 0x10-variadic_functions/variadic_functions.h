#ifndef VARIADIC_H
#define VARIADIC_H
#include <stdarg.h>
/**
 * struct func - structure func
 * @format_str: first member
 * @f: function pointer member
 * @type: data type rep by format_str
 */

typedef struct func
{
	char format_str;
	void (*f)();
} the_func;

int _putchar(char c);
int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

#endif /*VARIADIC_H */
