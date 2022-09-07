#include "main.h"

/**
 * _getline - reads a line from stream
 * @s: the buffer into which to read
 * @lim: the size limit
 * Return: size of buffer
 */
int _getline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return (i);
}

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
	if (n_read < 0)/*zero indicates EOF*/
	{
		unix_error("getline read error");
		return (-1);/*-1 indicates read() error*/
	}
	return (n_read);
}

/**
 * main - simple_shell's main routine
 * Return: 0 always
 */
int main(void)
{
	char *cmdline = NULL, *dirs; /*the command(line)*/
	d_t *head = NULL;
	res _res = {-1, -1}, *res = &_res;
	int n_read;
	size_t size = 0;

	Signal(SIGINT, sigint_handler);/*catch (CTRL + C)*/
	dirs = _getenv(environ, "PATH", res);/*get path directories*/
	create_path_list(dirs, &head);/*create a linked list of these directories*/
	while (1) /*only terminates if feof/builtin_command evaluates to true*/
	{
		/* Read cmd from stdin */
		write(1, "#cisfun$ ", 9);
		/*Fgets(cmdline, MAXLINE, stdin);*/
		/*n_read = getline(&cmdline, &size, stdin);*/
		n_read = get_line(&cmdline, &size, STDIN_FILENO);
		/*n_read = _getline(cmdline, MAXLINE);*/
		/*if (feof(stdin))checks EOF status and returns 1 if set*/
		printf("chars: %d\n", n_read);
		if (n_read == -1)
			exit(0);
		/* Evaluate the cmd */
		printf("cmdline: %s", cmdline);
		evaluate_command_line(cmdline, head);
	}
}
