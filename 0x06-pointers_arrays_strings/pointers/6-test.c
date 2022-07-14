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
	char c;
	char *pp;

	n = 98;
	p = &n; /*p points to the address of n*/
	c = 'H';
	pp = &c;
	printf("Value of 'n': %d\n", n);
	printf("Address of 'n': %p\n", &n);
	printf("Value of 'p': %p\n", p); /*should be same as the &n*/
	printf("Value of 'c': %c\n", c);
	printf("Address of 'c': %p\n", &c);
	printf("Value of 'pp': %p\n", pp); /*should be same as the &n*/
	*p = 402;
	*pp = 'o';
	printf("Value of 'n': %d\n", n); /*value of n shanges to 402*/
	printf("Value of '*p': %d\n", *p); /*dereference p - for the value in address it points to*/
	printf("Value of 'c': %d ('%c')\n", c, c);
	printf("Value of '*pp': %d ('%c')\n", *pp, *pp); /*a deref*/
	return (0);
}

