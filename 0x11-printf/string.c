#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_Str - writes a string to stdout, 1
 * @arg: the string to write
 * Description: writes the string passed as optional arg
 * to printf and handles non printable characters by
 * printing '\x' followed by their ascii code value in hex
 * (Uppercase - always 2 characters) 
 * Return: int number of bytes written
 */
int print_Str(va_list arg)
{
	int n = 0, i = 0;
	char *s, *_char = "\\x";
    /* for hex fn */
    int num, quot, k = 1, j, temp;
	char hold = '0', c[32];/*c'll hold the hex chars*/

	s = va_arg(arg, char *);
    while (s[i] != '\0')
    {
        if ((s[i] > 0 && s[i] < 32) || s[i] >= 127)
        {
            n += write(1, _char, strlen(_char));
            /*get & print the ascii code for that value*/
            num = s[i];
            if (num < 16)
                n += write(1, &hold, 1);
            quot = num;
            while(quot != 0)
            {
                temp = quot % 16;
                /*convert int to char*/
                if (temp < 10)
                {
                    temp += 48;
                }
                else
                {
                    temp += 55;/*i.e 10 = A = 65 - 10; for lowercase: +87 (97 = a)*/
                }
                c[k++] = temp;
                quot /= 16;

            }
            for (j = k - 1; j > 0; j--)
                n += write(1, c + j, 1);
        }
        else
        {
            n += write(1, s + i, 1);
        }
        i++;
    }
	return(n);
}

/**
 * print_pointer - prints the address of arg
 * @arg: the variable whose address to print
 * Return: int number of characters written (8)?
 */

int print_pointer(va_list arg)
{
	int n;
    void *value;

    /*i'm interested in the address of arg*/
    value = (va_arg(arg, void *));
    printf("\nptr: %x\n", value);
    n = write(1, value, 16);
	return (n);
}