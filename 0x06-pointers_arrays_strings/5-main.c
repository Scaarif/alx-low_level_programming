#include "main.h"
#include <stdio.h>
/**
 * main - check code
 * Return: always 0
 */

int main(void)
{
	char str[] = "Look up!";
	char *ptr;

	ptr = string_toupper(str);
	printf("%s\n", ptr);
	printf("%s\n", str);
	return (0);
}
