#include "main.h"
#include <stdio.h>
/**
 * main - check code
 * Return: always 0
 */

int main(void)
{
	char str[] = "Expect the best. Prepare for the worst. Capitalize on what comes\n";
	char *ptr;

	ptr = leet(str);
	printf("%s\n", ptr);
	printf("%s\n", str);
	return (0);
}