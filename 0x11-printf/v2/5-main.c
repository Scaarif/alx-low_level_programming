#include "main.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	void *addr;

	addr = (void *)0x7ffe637541f0;
	_printf("%S\n", "Best\nSchool");
	_printf("Address:[%p]\n", addr);
 	printf("Address:[%p]\n", addr);
	return (0);
}