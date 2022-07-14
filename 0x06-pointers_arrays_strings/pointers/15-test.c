#include <stdio.h>

/**
 * main - Illustrate the array tye decay
 * and pointers arithmetic
 * Return: 0 always
 */

int main(void)
{
	int a[5]; 
	int *p, *p2;

	*a = 98;
	*(a + 1) = 198;
	*(a + 2) = 298;
	a[3] = 398;
	*(a + 4) = 498;
	p = a + 1;
	*p = 98;
	p2 = a + 3;
	*p2 = *p + 1337;
	printf("*p: %d\n", *p);
	printf("*p = a + 1: %d\n", a[1]);
	printf("*p2: %d\n", *p2);
	printf("*p2 = a + 3: %d\n", a[3]);
	return (0);
}

