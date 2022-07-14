#include "main.h"
#include <stdio.h>

int main(void)
{
	int n;

	n = _atoi("98");
	printf("n=%d\n", n);
	n = _atoi("Suite 402");
	printf("n=%d\n", n);
    n = _atoi("---+++ -++ Siu -te - 403 #cisfun :)");
	printf("n=%d\n", n);
	return (0);
}