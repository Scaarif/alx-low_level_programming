#include "main.h"
#include <stdio.h>

int main(void)
{
	int n;

	n = _atoi("98");
	printf("%d\n", n);
	n = _atoi("Suite 402");
	printf("%d\n", n);
    n = _atoi("---+++ -++ Siu -te - 403 #cisfun :)");
	printf("%d\n", n);
	n = _atoi("-402");
	printf("%d\n", n);
	n = _atoi(" ------++++++-----+++++--98");
	printf("%d\n", n);
	n = _atoi("214748364");
	printf("%d\n", n);
	return (0);
}