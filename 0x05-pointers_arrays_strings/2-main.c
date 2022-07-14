#include <stdio.h>
#include "main.h"

int main(void)
{
	char *str;

	str = "My first strlen!";

	printf("n=%d\n", _strlen(str));
	return (0);
}