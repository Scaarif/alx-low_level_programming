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
int _printf(const char *format, ...);

#endif /* MAIN_H */
