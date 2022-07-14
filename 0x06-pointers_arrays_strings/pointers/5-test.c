#include <stdio.h>
/**
 * main - dereferencing pointers
 *
 * Return: always 0
 *
 */

int main(void)
{
	int *p; /*declare a pointer to a int type variable*/
	int n;

	n = 98;
	p = &n; /*p points to the address of n*/
	printf("Value of 'n': %d\n", n);
	printf("Address of 'n': %p\n", &n);
	printf("Value of 'p': %p\n", p); /*should be same as the &n*/
	*p = 402;
	printf("Value of 'n': %d\n", n); /*value of n shanges to 402*/
	return (0);
}

