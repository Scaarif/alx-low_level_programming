#include "main.h"
#include <stdio.h>

int main(void)
{
	int n;

	n = _printf("Damn, work man - %b\n", 98);
	_printf("%d\n", n);
	return (0);
}