#include <stdio.h>
#include "main.h"

/**
 * simple_print_buffer - prints buffer in hexa
 * @buffer: the address of memory to print
 * @size: the size of the memory to print
 *
 * Return: Nothing
 */
void simple_print_buffer(char *buffer, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (i < size)
	{
		if (i % 10) /*if true - i.e i%10 > 0*/
		{
			printf(" ");
		}
		if (!(i % 10) && i) /*if false and we still have i*/
		{
			printf("\n");
		}
		printf("0x%02x", buffer[i]); /*turns out 0x00 prints out as 0;*/
		/*%02x - sets min field width to 2 and pads (fills up) spaces with 0 hence 00 will be printed*/
		/*but, we print 0x first and therefore, end result is 0x00*/
		i++;
	}
	printf("\n");
}
/**
 * main - check the code 
 *
 * Return: always 0
 */
int main(void)
{
	char buffer[98] = {0};
	char buffer2[98] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};

	simple_print_buffer(buffer, 98);
	_memcpy(buffer + 50, buffer2, 10);
	printf("--------------------------------------------\n");
	simple_print_buffer(buffer, 98);
	return (0);
}
