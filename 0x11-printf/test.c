#include <stdio.h>
#include <string.h>
#include "main.h"

int main(void)
{
	int len2, len;
	char *str;
	/*unsigned int ui;*/
	/*void *addr;*/

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	str = "Let's try to printf a simple sentence.\n";
	printf("len2: %d, len2: %d strlen: %ld\n", len, len2, strlen(str));
	return (0);
}
