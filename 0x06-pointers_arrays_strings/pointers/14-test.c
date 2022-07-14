#include <stdio.h>

/**
 * main - Illustrate the array tye decay
 * Description: name of arry used in an epression 
 * the array type is automatically
 * implicitly converted to pointer-to-element type
 * Return: 0 always
 */

int main(void)
{
	int a[10]; /*declare an array of 10 elements*/
	int *p; /*pointer to int type elements*/
	int n;

	p = &n; /*this works because of the auto implicit conversion*/
	printf("p = &n;\np: %p\n", p);
	printf("p + 1: %p\n", p + 1);
	printf("p + 2: %p\n", p + 2);
	printf("p + 10: %p\n", p + 10);
	p = a; /*array decay - implicit conversion*/
	printf("p = a;\np: %p\np + 1: %p\n",p, p + 1);
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

