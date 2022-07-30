#include <stdio.h>

int power_10(int n)
{
	int pow;

	if (n == 0)
		pow = 1;
    else if (n == 1)
        pow = 10;
    else
    pow = 10 * power_10(n - 1);
	return (pow);
}

int main(void)
{
    int i = 3;

    printf("%d\n", power_10(i));
    return (0);
}
