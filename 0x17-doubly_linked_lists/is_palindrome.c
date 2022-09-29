#include "lists.h"
#include <string.h>

/**
 * str_reverse - reverse a string
 * @s: the string to reverse
 * Return: Nothing
 */
static void str_reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

/**
 * long_to_str - convert long to base b string
 * @v: the long int
 * @s: string to hold the long
 * @b: base to which to convert the long
 * Return: Nothing
 */
static void long_to_str(long v, char s[], int b)
{
	int c, i = 0;
	int neg = v < 0;

	if (neg)
		v *= -1;
	do {
		s[i++] = ((c = (v % b)) < 10) ? c + '0' : c + 'a';
	} while ((v /= b) > 0);

	if (neg)
		s[i++] = '-';
	s[i] = '\0'; /*terminate string*/
	str_reverse(s);
}

/**
 * is_palindrome - checks if a number is a palindrome
 * @n: the int to check
 * Return: 1 if true and 0 otherwise
 */
int is_palindrome(int n)
{
	char str[7];
	int len, i = 0, half;

	/* convert int into a string */
	long_to_str((long)n, str, 10);
	len = strlen(str);
	half = len / 2;
	while (half > 0)
	{
		/*printf("Comparing %c and %c\n", str[i], str[len]);*/
		if (str[i] != str[len - 1])
		{
			/*printf("Not pal\n");*/
			return (0);
		}
		i++;
		len--;
		half--;
	}
	/*printf("palindrome str num: %s\n", str);*/
	return (1);/*while loop exhausts*/
}

/**
 * product - gets the product of two three digit numbers
 * @a: first integer
 * @b: second integer
 * Return: product
 */
int product(int a, int b)
{
	return (a * b);
}

/**
 * main - check for max palindrome int of product of ints
 * between 100 and 999
 * Decsription: print the max palindrome found
 * Return: 0
 */
int main(void)
{
	int i = 100, j, max = 101, prod, nums[2];

	while (i < 1000)
	{
		j = i;
		while (j < 1000)
		{
			prod = product(i, j);
			if (is_palindrome(prod))
			{
				/*printf("palindrome prod: %d\n", prod);*/
				if (prod > max)
				{
					max = prod;
					nums[0] = i;
					nums[1] = j;
				}
			}
			j++;
		}
		i++;
	}
	if (is_palindrome(9009))
		printf("is_palindrome works!\n");
	else
		printf("is_palindrome DOESN'T work\n");
	printf("biggest palindrome prod is: %d => %d * %d\n", max, nums[0], nums[1]);
	return (0);
}


