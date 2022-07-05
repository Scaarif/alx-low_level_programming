#include "main.h"
#include <unistd.h>

/**
 * main - print using _putchar()
 *
 * Return: always 0
 *
 */
int main(void)
{
	char output[] = "_putchar";
	int i = 0;

	while (output[i] != '\0')
	{
		_putchar(output[i]);
		i++;
	}
	_putchar('\n');
	return (0);
}

int _putchar(char c)
{
	return (write(1, &c, 1));
}

