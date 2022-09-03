#include "main.h"

#define MAXARGS 128
/*#define MAXLINE 1024*/

/**
 * _cd - cd implementation using chdir and getcwd
 * @av: command line arguments array
 * Return: 0 on success and -1 otherwise
 */
int _cd(char **av)
{
	res a_res = {-1, -1}, *res = &a_res;
	char *pathname;

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
			chdir(pathname);
		else
			unix_error("_getenv error");
	}
	else
	{
		pathname = av[1];
		chdir(pathname);
	}
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
			printf("%s\n", environ[i]);
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
 * parseline - parse the cmdline and build the argv array
 * @buf: a copy of the cmd(line) from which to build argv
 * @argv: the array of strings, for execve fn
 * Return: int bg (1 or 0); a flag for background programs
 */
int parseline(char *buf, char **argv)
{
	char *delim;
	int argc, bg;

	buf[strlen(buf) - 1] = ' ';/* replace trailing /n with space */
	while (*buf && (*buf == ' '))
		buf++; /* ignore leading spaces; advance buf to 1st char */
	/* Build the argv array */
	argc = 0;
	while ((delim = strchr(buf, ' ')))
	{/*strchr returns pointer to 1st occurrence of ' ' in buf or NULL*/
		argv[argc++] = buf;
		*delim = '\0'; /*terminate 1st string*/
		buf = delim + 1; /*advance buf - to start of next string*/
		while (*buf && (*buf == ' '))
			buf++; /*ignore leading spaces*/
	}
	argv[argc] = NULL; /*last string*/
	if (argc == 0)
		return (1); /* ignore blank cmd(line) */
	/*is the job a back or foreground job?*/
	bg = (*argv[argc - 1] == '&');/*true = 1, else 0*/
	if (bg)
		argv[--argc] = NULL; /*remove the '&' from array*/
	return (bg);
}

/**
 * evaluate_command - evaluate the cmdline
 * i.e. the string/cmd typed/read from stdin
 * @cmdline: the command to evaluate
 * Return: Nothing
 */
void evaluate_command(char *cmdline)
{
	char *argv[MAXARGS], buf[MAXLINE];/*argv[] list for execve*/
	int status, bg; /*background programs flag*/
	pid_t pid;

	strcpy(buf, cmdline); /*cpy cmdline into buf*/
	bg = parseline(buf, argv);
	if (argv[0] == NULL)
		return; /*Ignore empty cmd lines*/
	if (!builtin_command(argv))
	{
		/*search for the executable in the PATH, if found, execute, else, don't!*/
		pid = Fork();
		if (pid == 0)
		{/* Child runs the user job (cmdline) */
			if (execve(argv[0], argv, environ) < 0)
			{/*an error has occurred i.e (-1) returned */
				printf("%s: Command not found.\n", argv[0]);
				exit(0);
			}
		}
		/*parent waits for foreground job to terminate*/
		if (!bg) /* i.e. if a foreground process (bg = 0)*/
		{
			if (waitpid(pid, &status, 0) < 0)/*wait for termination(fg_job) & reap*/
				unix_error("wait_fg: waitpid error");
		}
		else/* its a bg job (bg = 1), continue - no waiting or reaping!*/
		printf("%d %s", pid, cmdline);
		/*we could use SIGCHLD to reap the child, use a handler to catch it*/
	}
}


