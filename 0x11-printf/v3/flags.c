#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>


/**
 * manage_buffer - keep track of characters to be printed
 * @fmt: format argument of _printf
 * @str: the buffer at current state
 * Return: the buffer
 */
char *manage_buffer(const char *fmt, char *str, int start, int stop)
{
    int count = str[0] + 1, i = 1;/*how many bytes written to so far*/
    
    for (; count <= BUFFER && start < stop; count++, start++)
    {
        str[count] = fmt[start];
    }
    /*update str[0] at the end*/
    str[0] = count - 1;/* or is it - 2?*/
    printf("\nStr: ");
    for (; i <= str[0]; i++)
        printf("%c", *(str + i));
    printf("\n");
    return (str);
}

/**
 * handle_flag - literally
 * @c: flag character
 * Description: format is a string and contains
 * the optional format strings
 * Return: int number of bytes written
 */
int handle_flag(char c)
{
    int n = 0;
    /*char f[] = {'+', '-', '.', 'x'} x for int*/

    /* say i have a + */
    switch(c)
    {
        case '+':
            n += write(1, &c, 1);
            break;

    }
    return (n);
}

