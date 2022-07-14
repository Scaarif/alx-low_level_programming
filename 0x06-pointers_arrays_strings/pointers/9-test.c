#include <stdio.h>

int main(void)
{
	int a[5]; /*declare an array of 5 elements*/

	a[0] = 98;
	a[1] = 198;
	a[3] = 298;
	printf("Value of a[0]: %d\n", a[0]);
	printf("Value of a[1]: %d\n", a[1]);
	printf("Address of a[1]: %p\n", &a[1]);
	printf("Address of a[2]: %p\n", &a[2]);
	printf("Value of a[4]: %d\n", a[4]);
	return (0);
}

