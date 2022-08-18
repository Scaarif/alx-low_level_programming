#include <stdio.h>
#include <unistd.h>

/**
 * print_binary - converts unsigned int to binary
 * and writes it
 * @n: the unsigned long integer to turn into binary
 * Return: Nothing
 */

void print_binary(unsigned long int n)
{
	unsigned long int num, k;
    int _start = 0, i;
	char byte, *zero = "0";

	num = n;
	/*assuming size of 32 max bits*/
	for (i = 31; i >= 0; i--)
	{
		k = num >> i; /*right shift which is in essence dividing*/
		if (k & 1)
		{
			byte = '1';
            if (_start == 0)
                _start = i;
            write(1, &byte, 1);
            printf("\ni: %d & k: %lu\n", i, k);
		}
		else
		{
			byte = '0';
            if (_start)
            {
                write(1, &byte, 1);
                printf("\ni: %d & k: %lu\n", i, k);
            }
		}
	}
	if (_start == 0 && num != 1)/*we have all zeros*/
	{
		write(1, zero, 1);
	}
}

int main(void)
{
    print_binary(3);
    print_binary(3);
    print_binary(98);
    return (0);
}