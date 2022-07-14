#include <stdio.h>

int main(void)
{
	int *p; /*declare a pointer to a int type variable*/
	int n;

	n = 98;
	p = &n; /*p points to the address of n*/
	printf("Address of 'n': %p\n", &n);
	printf("Value of 'p': %p\n", p); /*should be same as the &n*/
	printf("Address of pointer: %p\n", &p); /*print the address of the pointer */
	return (0);
}

