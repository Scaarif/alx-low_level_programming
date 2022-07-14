#include <stdio.h>

/**
 * main - Illustrate pointers arithmetic
 * Return: 0 always
 */

int main(void)
{
	int a[10]; /*declare an array */
	int *p;

	*a = 98; /*same as *(a + 0) i.e. a[0]*/
	*(a + 1) = 198;
	*(a + 2) = 298;
	*(a + 3) = 398;
	*(a + 4) = 498; /* same as a[4] = 498 */
	printf("a: %p\n", a);
	printf("Value of t[0]: %d\n", *a);
	printf("Value of t[1]: %d\n", *(a + 1));
	printf("Value of t[2]: %d\n", *(a + 2));
	printf("Value of t[3]: %d\n", *(a + 3));
	printf("Value of t[4]: %d\n", *(a + 4));
	printf("--------------------\n");
	printf("Address/value of a: %p\n", a);
	printf("Address/value of a[1]: %p\n", (a + 1));
	printf("Address/value of a[1]: %p\n", &(*(a + 1)));
	printf("----------------\n");
	*(a + 9) = 999;
	printf("Value of a[9]: %d\n", *(a + 9));
	printf("Address of a[9]: %p\n", (a + 9));
	return (0);
}
/**
 * f - prints the value of a pointer of type int
 * @a: address of an integer we need to print
 *
 * Return: Nothing
 */
void f(int *a)
{
	printf("a: %p\n", a);
	return;
}

