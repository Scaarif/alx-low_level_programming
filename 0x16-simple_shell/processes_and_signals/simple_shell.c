#include "main.h"

/**
 * get_file - get file name to look for in PATH
 * from the pathname, if given
 * @pathname: the string to get file name from
 * Return: file name
 */
char *get_file(char *pathname)
{
	int i = 0, j = -1;
	char *file;

	for (; pathname[i] != '\0'; i++)
	{
		if (pathname[i] == '/')
			j = i;/*get pos of last / in pathname*/
	}
	if (j > -1)
	{
		file = pathname;
		for (j++, i = 0; (pathname[i] = file[j]) != '\0'; j++, i++)
			;
		pathname[j] = '\0';/*terminate name*/
	}
	/*else, there's no / - so filename provided*/
	return (pathname);
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
 * @head: head to path_dirs linked list
 * Return: Nothing
 */
void evaluate_command(char *cmdline, d_t *head)
{
	char *argv[MAXARGS], buf[MAXLINE], *file, pathname[PATH_S], *executable;
	int status, bg, i = 0; /*background programs flag*/
	pid_t pid;

	strcpy(buf, cmdline); /*cpy cmdline into buf*/
	bg = parseline(buf, argv);
	if (argv[0] == NULL)
		return; /*Ignore empty cmd lines*/
	/*determine no of commands in line, and for each, run through this process*/
	if (!builtin_command(argv))
	{
		for (; (pathname[i] = argv[0][i]) != '\0'; i++)
			;/*search for the executable in the PATH*/
		pathname[i] = '\0';
		file = get_file(pathname);
		executable = parse_path(&head, file);
		if (executable)/*argv[0] = file to search*/
		{
			pid = Fork();
			if (pid == 0)
			{/* Child runs the user job (cmdline) */
				if (execve(executable, argv, environ) < 0)/*error occurred(-1) returned */
					unix_error("execve error"), exit(1);
			}
			/*parent waits for foreground job to terminate*/
			if (!bg) /* i.e. if a foreground process (bg = 0)*/
			{
				if (waitpid(pid, &status, 0) < 0)/*wait for termination(fg_job) & reap*/
					unix_error("wait_fg: waitpid error");
			}
			else/* its a bg job (bg = 1), continue - no waiting or reaping!*/
			_write(buf, "background job", ": parent free to continue...\n");
			/*we could use SIGCHLD to reap the child, use a handler to catch it*/
		}
		else
		{
			/*printf("%s: executable not found.\n", argv[0]);*/
			_write(buf, argv[0], ": executable not found.\n");
		}
	}
}


