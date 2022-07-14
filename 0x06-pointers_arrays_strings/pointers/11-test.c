#include <stdio.h>

void f(int *a);
/**
 * main - Illustrate the array tye decay
 * Description: name of arry used in an epression 
 * the array type is automatically
 * implicitly converted to pointer-to-element type
 * Return: 0 always
 */

int main(void)
{
	int t[10]; /*declare an array of 10 elements*/
	int *p; /*pointer to int type elements*/

	p = t; /*this works because of the auto implicit conversion*/
	printf("t: %p\n", t);
	printf("Address of t[0]: %p\n", &t[0]);
	printf("Address/value of p: %p\n", p);
	f(t);
	return (0);
}
/**
 * f - prints the value of a pointer of type int
 * @a: address of an integer we need to print
 *
 * Return: Nothing
 */
void f(int *a)
{
	printf("a: %p\n", a);
	return;
}

