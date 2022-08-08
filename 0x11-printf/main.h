#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

typedef struct specifier
{
	char *s;
	int (*f)();/*optional args?*/
} fn;

int is_specifier(const char *str, int index);
int *get_indices(const char *str);
int print_string(const char *s, int start, int stop);
int print_str(va_list arg);
int print_char(va_list arg);
int print_int(va_list arg);
int print_binary(va_list arg);
int make_unsigned(va_list arg);
int print_octal(va_list arg);
int _printf(const char *format, ...);
int _num(long n);
void _print_num(long n);

#endif /* MAIN_H */
