#include "3-calc.h"
#include <stdlib.h>

/**
 * get_op_func - selects the correct function to perform
 * the user asked operation
 * @s: string operation asked to be performed
 * Return: a pointer to the selected function
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL},
	};
	int i;

	/*returns pointer to fn: equivalent to fn_name*/
	i = 0;
	while (i < 5)
	{
		if (s[0] == ops[i].op[0])
			return (ops[i].f);
		i++;
	}
	/*else the operation is out of the allowed range*/
	return (NULL);
}


