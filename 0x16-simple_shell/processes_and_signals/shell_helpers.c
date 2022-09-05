#include "main.h"

/**
 * _write - print simple lines to stdout
 * @buf: buffer to hold string to write
 * @str: accompanying string, say name
 * @msg: customized message string
 * Return: no of characters written
 */
int _write(char *buf, char *str, char *msg)
{	int len = 0, i = 0;

	for (; (buf[len] = str[i]) != '\0'; i++, len++)
	      ;
	for (i = 0; (buf[len] = msg[i]) != '\0'; len++, i++)
		;
	i = write(1, buf, len);	
	return (i);
}

/**
 * _cd - cd implementation using chdir and getcwd
 * @av: command line arguments array
 * Return: 0 on success and -1 otherwise
 */
int _cd(char **av)
{
	res a_res = {-1, -1}, *res = &a_res;
	char *pathname, _pwd[MAXLINE];

	getcwd(_pwd, MAXLINE);/*get current working directory*/
	if (av[1] == NULL)/*only one arg, cd - go back $home*/
	{
		pathname = _getenv(environ, "HOME", res);
		if (pathname)
			chdir(pathname);
		else
			unix_error("_getenv error");
	}
	else if (strcmp(av[1], "-") == 0)
	{
		pathname = _getenv(environ, "OLDPWD", res);
		if (pathname)
		{
			printf("%s\n", pathname);
			chdir(pathname);
		}
		else
			unix_error("_getenv error");
	}
	else
	{
		pathname = av[1];
		chdir(pathname);
	}
	/*reset oldpwd's value to current pwd*/
	_setenv("OLDPWD", _pwd, 1);
	/*change environ's pwd to pathname*/
	return (_setenv("PWD", pathname, 1));
}
