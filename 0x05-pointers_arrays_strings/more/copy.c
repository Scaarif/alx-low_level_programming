#include <stdio.h>
#include <string.h>

int main(void)
{
	char *str = "Hello there! First, solve the problem. Then, write the code";
	char cpy[90];
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		cpy[i] = str[i];
	}
	cpy[i + 1] = '\0';
	printf("str: %s\n", str);
	printf("cpy: %s\n", cpy);
	printf("str: %p\n", str);
	printf("cpy: %p\n", cpy);
	return (0);
}


