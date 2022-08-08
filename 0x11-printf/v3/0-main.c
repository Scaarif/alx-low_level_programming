#include "main.h"
#include <stdio.h>

int main(void)
{
	int len;
	/*unsigned int ui;*/
	/*void *addr;*/

	printf("output from _printf:\n");
	len = _printf("%s: That is 100%% Ra%cab, and %s too - 100%%!\n", "S.N",'H', "Scaarif");
	/*len = print_string("Let's try to printf a simple sentence.\n");*/
	/*len2 = printf("Let's try to printf a simple sentence.\n");*/
	/* printf("len: %d, len2: %d strlen: %ld\n", len, len2, strlen(str));*/
	printf("len: %d\n", len);
	/*len = _printf("100%% %s aka Ra%cab %s\n", "Scaarif", 'H', "Ngache");*/
	return (0);
}