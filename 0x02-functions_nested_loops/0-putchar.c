#include <unistd.h>
#include "main.h"

/**
 * main - print "_putchar"
 *
 * Return: always 0
 *
 */
int main(void)
{
	char ouput[] = "_putchar";
	int i = 0;

	while (ouput[i] != '\0')
	{
		_putchar(ouput[i]);
		i++;
	}
	_putchar('\n');
	return (0);
}

int _putchar(char c)
{
        return (write(1, &c, 1));
}
