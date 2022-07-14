#include "main.h"
#include <stdio.h>

int main(void)
{
	int a, b;

	a = 98;
	b = 42;

	printf("a=%d, b=%d\n", a, b);
	swap_int(&a, &b); /*memory addresses of a and b are the input parameters*/
	printf("a=%d, b=%d\n", a, b);
	return (0);
}