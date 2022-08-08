#include "main.h"
#include <stdio.h>

int main(void)
{
	int len;
	/*unsigned int ui;*/
	/*void *addr;*/

	printf("output from _printf:\n");
	/*len = _printf("%s: %d\n", "S.N", 1);*/
	len = _printf("%s: %i%%!\n", "Rahab", -762534);
	/*len = print_string("Let's try to printf a simple sentence.\n");*/
	/*len2 = printf("Let's try to printf a simple sentence.\n");*/
	/* printf("len: %d, len2: %d strlen: %ld\n", len, len2, strlen(str));*/
	_printf("my_len: %d\n", len);
	len = printf("%s: %i%%\n", "Rahab", -762534);
	printf("len: %i\n", len);
	/*len = _printf("100%% %s aka Ra%cab %s\n", "Scaarif", 'H', "Ngache");*/
	return (0);
}