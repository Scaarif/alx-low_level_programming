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

/**
 * builtin_command - check if argv[0] is a built-in cmd
 * @argv: the command(line) as **argv, array of strings
 * Return: 1 if true and 0 otherwise
 */
int builtin_command(char **argv)
{
	int i = 0;
	char buf[MAXLINE];

	if (!strcmp(argv[0], "exit"))/*i.e if command is exit*/
	{
		if (argv[1])
			exit(atoi(argv[1]));/*handle exit argument/status*/
		exit(0);/*terminate process*/
	}
	if (!strcmp(argv[0], "env"))/*i.e if command is env*/
	{
		/*print environ*/
		for (; environ[i] != NULL; i++)
			_write(buf, environ[i], "\n");
		/*printf("%s\n", environ[i]);*/
		return (1);/*i.e return true - builtin command*/
	}
	if (!strcmp(argv[0], "cd"))/*i.e if command is exit*/
	{
		return (!_cd(argv));
	}
	if (!strcmp(argv[0], "&")) /*ignore singleton &*/
		return (1);
	return (0); /*i.e. not a built in command*/
}

/**
 * _strlen - strlen()
 * @s: string whose length to return
 * Return: length of string
 */
int _strlen(char s[])
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}
