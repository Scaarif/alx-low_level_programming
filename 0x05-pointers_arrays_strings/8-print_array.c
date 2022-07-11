#include "main.h"
#include <stdio.h>

int main(void)
{
	int a[5];

	a[0] = 98;	
	a[1] = 402;	
	a[2] = -198;	
	a[3] = 298;	
	a[4] = -1024;
	print_array(a, 5);	
	return (0);
}

/**
 * print_array - prints n elements in an array
 * @a: array of integers
 * @n: number of elememnts to print
 * Return: void
 */
void print_array(int *a, int n)
{
	int i = 0;

	while (i < (n - 1))
	{
		printf("%d, ", a[i]);
		i++;
	}
	if (i == (n - 1))
		printf("%d\n", a[i]);
}
