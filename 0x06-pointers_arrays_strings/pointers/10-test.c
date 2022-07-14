#include <stdio.h>

int main(void)
{
	int a[5]; /*declare an array of 5 elements*/

	a[0] = 98;
	printf("Value of a[0]: %d\n", a[0]);
	printf("Address of a[0]: %p\n", &a[0]);
	printf("Address/value of a: %p\n", a);/*value of a = pointer to first element address*/
	return (0);
}

