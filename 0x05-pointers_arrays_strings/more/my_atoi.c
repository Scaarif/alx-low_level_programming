#include "main.h"
#include <stdio.h>


/**
 * get_len - return length of string
 * @s: the string
 * Return: length
 */
int get_len(char *s)
{
	int i;
	
	for (i = 0; s[i] != '\0'; i++);
	return (i);
}

/**
 * first_index - return index first integer in string
 * @s: the string
 * Return: index
 */
int first_index(char *s)
{
	int i = 0, index = -1;

	for (; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9' && s[i] != '\0')
		{
			index = i;
			break;
		}
	}
	return (index);
}

/**
 * sign - return positive or negative
 * @s: the string
 * Description: takes account of all the negatives
 * before the integer in the string
 * an odd number means a negative sign
 * Return: sign
 */
int sign(char *s)
{
	int sign = 1, i = 0, negatives = 0;

	for (; s[i] != '\0'; i++)
	{
		if (s[i] == '-')
		{
			negatives++;
		}
	}
	if (negatives % 2 != 0)
		sign *= -1;
	return (sign);
}

/**
 * power - return the power
 * @p: int one
 * @n: int two
 * Return: the nth power of p
 */
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

/**
 * _atoi - convert string into integer
 * @s: the string
 * Return: the integer
 */

int _atoi(char *s)
{
	int sig, i, num = 0, digits = 0, tens = 10;
	/*find length of string*/
	int len = get_len(s);
	/*find if a digit appears in the string*/
	int index0 = first_index(s);
	/* printf("index0: %d\n", index0); */

	/*determine sign of integer*/
	if (index0 >= 0)
	{
	       sig = sign(s);
		   /* printf("sign: %d\n", sig); */

	       /*find number of digits*/
	       while (s[index0] >= '0' && s[index0] <= '9' && index0 < len)
	       {
		       digits++;
		       index0++;
		   }
		   /* printf("digits: %d\n", digits); */ 
		   /* printf("index0: %d\n", index0); */ 

	       /*the integer is */
		   i = 0;
	       while (i < digits)
	       {
		       tens = power(10, i); /*index0 = last digit in string*/
		       num += (s[index0 - 1] - '0') * tens;
			   /* printf("num: %d\n", num); */
			   index0--;
		       i++;
	       }
	}
	else
	{
		return (0);
	}
	return (sig * num);
}





