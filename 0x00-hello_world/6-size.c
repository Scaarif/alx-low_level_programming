#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: 'prints out size of datatypes'
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int intType;
	float floatType;
	long int longIntType;
	long long int llit;
	char charType;

	printf("Size of a char: %zu byte(s)\n", sizeof(charType));
	printf("Size of an int: %zu byte(s)\n", sizeof(intType));
	printf("Size of a long int: %zu byte(s)\n", sizeof(longIntType));
	printf("Size of a long long int: %zu byte(s)\n", sizeof(llit));
	printf("Size of a float: %zu byte(s)\n", sizeof(floatType));

	return (0);
}
