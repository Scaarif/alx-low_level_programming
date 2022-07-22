#include <stdio.h>
#include <stdlib.h>
/**
 * main - prints the minimum number of cents
 * to make change for an amount of money
 * Description: prints Error if argc == 2 and
 * returns 1
 * @argc: arg count
 * @argv: args array
 * Return: 0 on success, else 1
 */
int main(int argc, char **argv)
{
	int cents, num = 0;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	cents = atoi(argv[1]);
	if (cents > 0)
	{
		num += cents / 25 + (cents % 25) / 10 + ((cents % 25) % 10) / 5
		+ (((cents % 25) % 10) % 5) / 2 + ((((cents % 25) % 10) % 5) % 2) / 1;
		printf("%d\n", num);
		return (0);
	}
	printf("0\n");
	/**
	* Description:shorter more direct solution
	* num += cents / 25 + (cents % 25) / 10 +
	* ((cents % 25) % 10) / 5 + (((cents % 25) % 10) % 5) / 2
	* + ((((cents % 25) % 10) % 5) % 2) / 1
	*/
	return (0);
}

