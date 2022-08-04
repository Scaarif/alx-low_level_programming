#include "function_pointers.h"

/**
 * print_name - prints a name
 * @name: string name
 * @f: pointer to a void returning function
 * that takes an array of chars as argument
 * Return: Nothing
 */

void print_name(char *name, void (*f)(char *))
{
	/*calls back the fn passed to it with name as arg*/
	if (name != NULL && f != NULL)
		f(name);
}

