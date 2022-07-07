#include <stdio.h>
/**
 * main - prints numbers from 1 to 100
 * Description: in place of multiples of 3 it prints Fizz
 * in place of multiples of 5, Buzz
 * and in place of multiples of both, FizzBuzz
 * Return: 0
 */

int main(void)
{
	int a = 0;

	while (a < 100)
	{
		a++;

		if (a % 3 == 0 && a % 5 == 0)
			printf("FizzBuzz ");
		else if (a % 3 == 0)
			printf("Fizz ");
		else if (a % 5 == 0)
			printf("Buzz ");
		else
			printf("%d ", a);
	}
	printf("\n");
	return (0);
}
