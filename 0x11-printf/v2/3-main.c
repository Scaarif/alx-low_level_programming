#include "main.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	unsigned int ui;

	ui = (unsigned int)INT_MAX + 1024;
 	_printf("%u\n", 98);
	_printf("%u\n", -98);
	_printf("Unsigned:[%u]\n", ui);
	printf("Unsigned:[%u]\n", ui);
	_printf("Unsigned hex:[%x %X]\n", ui, ui);
	printf("Unsigned hex:[%x %X]\n", ui, ui);
	return (0);
}