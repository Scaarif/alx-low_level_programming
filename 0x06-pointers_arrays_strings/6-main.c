#include "main.h"
#include <stdio.h>
/**
 * main - check code
 * Return: always 0
 */

int main(void)
{
	char str[] = "Expect the best. Prepare for the worst. Capitalize on what comes .\nhello world! hello-world 0123456hello world\thello world.hello world\n";
	char *ptr;

	ptr = cap_string(str);
	printf("%s\n", ptr);
	printf("%s\n", str);
	return (0);
}