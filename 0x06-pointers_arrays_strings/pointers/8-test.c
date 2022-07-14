#include <stdio.h>
/**
 * main - dereferencing pointers
 *
 * Return: always 0
 *
 */
void modify_my_char(char *cc, char ccc)
{
	*cc = 'o'; /*modify the value at pointed address*/
	ccc = 'l';
}

int main(void)
{
	char *p; /*declare a pointer to a int type variable*/
	char c;

	p = &c;
	c = 'H';
	printf("Value of 'c': %c\n", c); /*should be same as the &n*/
	printf("Value of 'p': %p\n", p);
	modify_my_char(p, c);
	printf("Value of 'c' after the call to fn: %c\n", c); /*value of n shanges to 402*/
	return (0);
}

