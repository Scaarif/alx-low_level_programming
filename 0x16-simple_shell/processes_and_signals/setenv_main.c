#include "main.h"

char *globalValue(char *name, res *res)
{
	return (_getenv(environ, name, res));
}

/**
 * main - demonstrate/interrogate the working of
 * setenv() and unsetenv() functions
 * Finding: they only change the variables locally
 * the global env remains the same and therefore as soon as the process 
 * terminates, the value ceases to exist (returns to original value)
 * Return: 0 Always
 */

int main(void)
{
	char *name, *value;
	res res = {-1, -1}, *a_res = &res;

	name = "NAME1";
	value = _getenv(environ, name, a_res);
	printf("%s: %s\n", name, value);
	_setenv(name, "test value", 1);
	value = _getenv(environ, name, a_res);
	printf("%s: %s\n", name, value);
	_unsetenv(name);
	printf("\n*** WE'VE JUST DELETED THE VARIABLE! ***\n\n");
	_setenv(name, "newer value", 1);
	value = _getenv(environ, name, a_res);
	printf("(from _setenv)%s: %s\n", name, value);
	/*value = globalValue(name, a_res);*/
	/*printf("from a fn:\n%s: %s\n", name, value);*/
	/*unsetenv(name);*/
	value = _getenv(environ, name, a_res);
	printf("%s: %s\n", name, value);
	return (0);
}

/*/bin/bash*/
