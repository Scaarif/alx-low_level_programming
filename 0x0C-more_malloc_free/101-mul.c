#include <stdlib.h>
#include <stdio.h>

long int get_num(char *s);
int power_10(int n);

/**
 * main - multiply two numbers
 * @argc: no of cmd line arguments
 * @argv: array of pointers to args
 * Return: 0 if success and 98 if failure
 */

int main(int argc, char **argv)
{
	int i, j;
	long int num1, num2;

	if (argc < 3)
	{
		printf("Error\n");
		exit(98);
	}
	/*check characters for non-digits*/
	for (i = 1; i < argc; i++)
	{
		for (j = 0; *(argv[i] + j) != '\0'; j++)
		{
			if (*(argv[i] + j) < '0' || *(argv[i] + j) > '9')
			{
				printf("Error\n");
				exit(98);
			}
			/*printf("argv_j: %c\n", *(argv[i] + j));*/
		}
		/*printf("argv: %s\n", argv[i]);*/
	}
	/*printf("power: %d\n", power_10(6));*/
	/*the numbers seem to be in order, change strs into ints*/
	num1 = get_num(argv[1]);
	num2 = get_num(argv[2]);
	printf("%ld\n", num1 * num2);
	exit(0);
}

/**
 * power_10 - raises 10 to the power of n
 * @n: integer power required
 * Return: int power
 */
int power_10(int n)
{
	int pow = 1;

	if (n == 0)
		pow *= 1;
	else
		pow = 10 * power_10(n - 1);
	return (pow);
}

/**
 * str_len - returns length of a string
 * @s: string
 * Return: int length
 */
int str_len(char *s)
{
	int len = 0;

	for (; s[len] != '\0'; len++)
	len++;
	return (len);
}

/**
 * get_num - turns string into number
 * @s: string
 * Return: long int number
 */
long int get_num(char *s)
{
	long int num = 0;
	int i, len;

	len = str_len(s);
	/*printf("len: %d\n", len);*/
	/*printf("argv_s: %s\n", s);*/
	/*printf("argv_s_0: %c\n", s[0]);*/
	/*printf("argv_s_1: %c\n", s[1]);*/
	len--;
	for (i = 0; len >= 0; i++, len--)
	{
		/*printf("argv_s_i: %c\n", s[i]);*/
		/*printf("pow: %d\n", power_10(len));*/
		num += ((s[i] - '0') % 10) * power_10(len);
	}
	/*printf("num: %ld\n", num);*/
	return (num);
}
