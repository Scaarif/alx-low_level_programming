#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

/**
 * handle_flag - literally
 * @c: flag character
 * Description: format is a string and contains
 * the optional format strings
 * Return: int number of bytes written
 */
int handle_flag(char c)
{
    int n = 0, pos;
    /*char f[] = {'+', '-', '.', 'x'} x for int*/

    /* say i have a + */
    switch(c)
    {
        case '+':
            pos = check_num(va_list n);
            if (pos)
                n += write(1, &c, 1);
            break;

    }
    return (n);
}