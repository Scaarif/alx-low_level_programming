#include "main.h"

/**
 * _getline1 - reads a line from stream
 * @s: pointer to string buffer into which to read
 * @lim: pointer to buffer size limit
 * @fd: stream to read from
 * Return: no of characters read
 */
int _getline1(char *s, int lim, int fd)
{
	int n_read;

	n_read = read(fd, s, lim);
	if (n_read < 0)
	{
		unix_error("getline read error");
		return (-1);
	}
	return (n_read);
}

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
 * main - simple_shell's main routine
 * Return: 0 always
 */
int main(void)
{
	char cmdline[MAXLINE], *dirs; /*the command(line)*/
	d_t *head = NULL;
	res _res = {-1, -1}, *res = &_res;

	dirs = _getenv(environ, "PATH", res);/*get path directories*/
	create_path_list(dirs, &head);/*create a linked list of these directories*/
	while (1) /*infinite loop - only terminates if feof/builtin_command evaluates to true*/
	{
		/* Read cmd from stdin */
		write(1, "#cisfun$ ", 9);
		Fgets(cmdline, MAXLINE, stdin);
		/*_getline1(cmdline, MAXLINE, STDIN_FILENO);*/
		if (feof(stdin))/*checks EOF status and returns 1 if set*/
			exit(0);
		/* Evaluate the cmd */
		evaluate_command(cmdline, head);
	}
}
