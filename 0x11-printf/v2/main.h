#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

#define BUFFER 1024

typedef struct specifier
{
	char *s;
	int (*f)(va_list, ...);
} fn;

int is_specifier(const char *str, int index);
int *get_indices(const char *str);
int print_string(const char *s, int start, int stop);
int print_str(va_list arg, ...);
int print_char(va_list arg, ...);
int print_int(va_list arg, ...);
int print_binary(va_list arg, ...);
int make_unsigned(va_list arg, ...);
int print_octal(va_list arg, ...);
int print_hex(va_list arg, ...);
int print_heX(va_list arg, ...);
int _printf(const char *format, ...);
int _num(long n);
void _print_num(long n);
int print_Str(va_list arg, ...);
int print_pointer(va_list arg, ...);
int handle_flag(char c);

#endif /* MAIN_H */
