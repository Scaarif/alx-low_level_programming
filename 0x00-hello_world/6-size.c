#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: 'print to stdout the sizeof types'
 *
 * Return: Always 0 (Success)
 *
 */

int main(void)
{
	char typeChar;
	int typeInt;
	float typeFloat;
	long int typeLongInt;
	long long int typeLongLong;

	printf("Size of char: %lu byte(s)\n", sizeof(typeChar));
	printf("Size of int: %lu byte(s)\n", sizeof(typeInt));
	printf("Size of float: %lu byte(s)\n", sizeof(typeFloat));
	printf("Size of long int: %lu byte(s)\n", sizeof(typeLongInt));	
	printf("Size of long long int: %lu byte(s)\n", sizeof(typeLongLong));

	return (0);
}

