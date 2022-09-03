#include "main.h"

/**
 * main - getenv() in action
 * Return: always 0
 */
int main(void)
{
	char *val, *name;

	name = "PATH";
	val = getenv(name);
	if (val)
		printf("%s: %s\n", name, val);
	else
		unix_error("getenv error");
	return (0);
}

