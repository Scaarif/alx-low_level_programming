#include <stdio.h>

int power(int p, int n)
{
	int res;
	if (n == 0)
		res = 1;
	else if (n == 1)
		res = p;
	else
		res = p * power(p, n - 1);
	return (res);
}

int main(void)
{
	printf("10 ** 2: %d\n", power(10, 0));
	return (0);
}

	

