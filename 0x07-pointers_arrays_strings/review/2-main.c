#include "main.h"
#include <stdio.h>
/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
 char *s = "world";
 char *f;
 f = _strchr(s, 'r');
 if (f != NULL)
 {
 printf("%s\n", f);
 }
 return (0);
}
