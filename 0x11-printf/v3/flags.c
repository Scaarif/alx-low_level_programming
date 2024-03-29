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
 * @start: int index
 * @stop: int index
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
 * manage_buffer_with_pointers - keep track of characters to be printed
 * @str: the buffer at current state
 * @c: character to append to str
 * Return: the buffer
 */
char *manage_buffer_with_pointers(char *str, char c)
{
    int count = str[0] + 1, stop = count + 1, i = 1;/*how many bytes written to so far*/
    
    for (; count < stop; count++)
    {
        str[count] = c;
        /*printf("i.e.: %c", *(str + count));*/
    }
    /*update str[0] at the end*/
    str[0] = count - 1;/* or is it - 2?*/
    printf("\npointer_Str: ");
    for (; i <= str[0]; i++)
        printf("%c", *(str + i));
    printf("\n");
    return (str);
}

/**
 * handle_flag - literally
 * @c: flag character
 * @str: buffer
 * Description: format is a string and contains
 * the optional format strings
 * Return: int number of bytes written
 */
int handle_flag(char c, char *str)
{
    int n = 0, num, last_index;
    char filler = '*';

    /* say i have a + */
    switch(c)
    {
        case '+':
            n += write(1, &c, 1);
            manage_buffer_with_pointers(str, c);
            break;
         case ' ':
            n += write(1, &c, 1);
            manage_buffer_with_pointers(str, c);
            break;
        case '#':
            n += write(1, &c, 1);
            manage_buffer_with_pointers(str, c);
            break;
        case '.':
            n += write(1, &c, 1);
            manage_buffer_with_pointers(str, c);
            break;
        case '0':
            n += write(1, &c, 1);
            manage_buffer_with_pointers(str, c);
            break;
        default:
            /*an integer for width specification*/
            num = c - '0';
            last_index = str[0]; 
            if (str[last_index] == '0')
                str[0] = last_index - 1;/*overwrite the appended 0*/
            for (; num > 0; num--)
            {
                n += write(1, &filler, 1);
                manage_buffer_with_pointers(str, filler);
            }
    }
    return (n);
}
/**
 * get_width - returns the filed width specifier 
 * @fmt: buffer
 * @idx: index of last character in str(fmt)
 * Return: the width
 */
int get_width(char *fmt, int idx)
{
    int width = 0;

    if (fmt[idx] == '-')
        idx--;
    printf("last char: %c\n", fmt[idx]);
    for (; fmt[idx] == '*'; idx--, width++)
        ;
    return (width);
}