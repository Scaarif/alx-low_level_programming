#include <stdio.h>
/**
 * main - dereferencing pointers
 *
 * Return: always 0
 *
 */
void modify_my_param(int *m)
{
	printf("Value of 'm': %p\n", m); /*m is a pointer*/
	printf("Address of 'm': %p\n", &m);
	*m = 402; /*modify the value at pointed address*/
}

int main(void)
{
	int *p; /*declare a pointer to a int type variable*/
	int n;

	n = 98;
	p = &n; /*p points to the address of n*/
	printf("Value of 'n': %d\n", n);
	printf("Address of 'n': %p\n", &n);
	printf("Value of 'p': %p\n", p); /*should be same as the &n*/
	printf("Address of 'p': %p\n", &p);
	modify_my_param(p);
	printf("Value of 'n' after the call to fn: %d\n", n); /*value of n shanges to 402*/
	return (0);
}

