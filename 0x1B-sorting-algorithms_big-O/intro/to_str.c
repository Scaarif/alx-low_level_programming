#include <unistd.h>
#include <stdio.h>

/**
 * str_len - returns the length of a string, array of chars
 * @str: the string whose length to calculate
 * Return: the length (no of characters in string)
 */
int str_len(char *str)
{
	int len = 0;

	for (; str[len] != '\0'; len++)
		;
	return len;
}

/**
 * reverse_str - reverses the order of chars in a string
 * @str: the string to reverse
 * Return: Nothing
 */
void reverse_str(char str[])
{
	int i = 0, j;
	char temp;

	for (j = str_len(str) - 1; i < str_len(str) / 2; i++, j--)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}	
}

/**
 * to_str - converts a long int into a string
 * @num: the integer to convert
 * @num_str: the array to hold the long int string
 * Return: Nothing
 */
void to_str(long int num, char num_str[])
{
	int i = 0, neg = 0;

	/* check if num is negative */
	if (num < 0)
	{
		neg = 1;
		num *= -1; /* make it positive */
	}
	/*get the individual numbers in int & append to num_str */
	while (num)
	{
		num_str[i++] = '0' + num % 10; /*i'll have to reverse the str */
		/*printf("%c ", num_str[i - 1]);*/
		num /= 10;
	}
	if (neg)
		num_str[i++] = '-';
	num_str[i] = '\0'; /*terminate*/
	reverse_str(num_str);
}

int main(void)
{
	long int num = 123456;
	char num_str[250];

	to_str(num, num_str);
	printf("%ld string is: %s\n", num, num_str);
	return (0);
}
