#include "main.h"
#include <stdio.h>

int main(void)
{
	int n;

	n = _atoi("98");
	printf("n=%d\n", n);
	n = _atoi("Suite 402");
	printf("n=%d\n", n);
	return (0);
}

/**
 * _atoi - convert a string to an integer
 * @s: string argument
 * Return: converted int
 */
int _atoi(char *s)
{
	int i = 0, k = 0;
	int *res;

	while (s[i] != '\0')
	{
		if (s[i] >= 48 && s[i] <= 57)
		{
			if (s[i - 1] == '+' || s[i - 1] == '-')
				res[k] = s[i-1];
			k++;
			res[k] = s[i];
			k++;
			if (!(s[i + 1] >= 48 && s[i + 1] <= 57))
				break;
		}
		i++;
	}
	return (res);
}
