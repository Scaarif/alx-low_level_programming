#include <stdio.h>

/**
 * power - returns the power of 2 integers
 * @a: int 1
 * @b: int 2
 * Return: the unsigned int power/result
 */
unsigned int power(int a, int b)
{
	int pow;

	
	if (b < 0)
		pow = -1;
	else if (b == 0)
		pow = 1;
	else if (b == 1)
		pow = a;
	else
		pow = a * power(a, b - 1);
	return ((unsigned int)pow);
}

int main(void)
{
	int a = 4, b = 4, pow, i, j;
	char *s = "101";

	pow = power(a, b);
	printf("power: %d\n", pow);
	for (i = 0; s[i] != '\0'; i++)
		;
	printf("strlen: %d\n", i);
	for (i--, j = 0; i >= 0; i--, j++)
		printf("char: %c & int: %d\n", s[i], s[i] - '0');
	return (0);
}