#include "main.h"

/**
 * check_for_delims - check for delimeters in commandline
 * @cmdline: the command_line
 * @delims: the delims to check for
 * @res: an array of the delims in cmdline
 * Return: a string of delimiters found
 */
char *check_for_delims(char *cmdline, char *delims, char *res)
{
	int i = 0, j = 0, k = 0;

	for (; delims[i] != '\0'; i++)
	{
		for (j = 0; cmdline[j] != '\0'; j++)
		{
			if (delims[i] == cmdline[j])
			{
				res[k++] = cmdline[j];
				break;
			}
			/*printf("char: %c\n",cmdline[j]);*/
		}
		/*printf("delim checked: %c\n", delims[i]);*/
	}
	res[k] = '\0';/*terminate it*/
	return (res);
}


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
 * parse_line - parse the cmdline and build the argv array
 * @buf: a copy of the cmd(line) from which to build argv
 * @argv: the array of strings, for execve fn
 * @del: the delimiting character in during parsing
 * Return: int bg (1 or 0); a flag for background programs
 */
int parse_line(char *buf, char **argv, char del)
{
	char *delim;
	int argc, bg;

	buf[_strlen(buf) - 1] = del;/* replace trailing /n with space */
	while (*buf && (*buf == ' '))
		buf++; /* ignore leading spaces; advance buf to 1st char */
	/* Build the argv array */
	argc = 0;
	/*printf("Parsing_line\n");*/
	while ((delim = _strchr(buf, del)))
	{/*_strchr returns pointer to 1st occurrence of ' ' in buf or NULL*/
		argv[argc++] = buf;
		*delim = '\0'; /*terminate 1st string*/
		buf = delim + 1; /*advance buf - to start of next string*/
		while (*buf && ((*buf == del) || (*buf == ' ')))
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
 * evaluate_command - evaluate the command after parsing command_line
 * & update success_status (the exit status of a command)
 * @argv: the array for an individual command to evaluate
 * @head: head to path_dirs linked list
 * @bg: flag, background or foreground process
 * @status: pointer to exit status flag
 * Return: Nothing
 */
void evaluate_command(char **argv, d_t *head, int bg, int *status)
{
	char  *file, pathname[PATH_S], buf[MAXLINE], *executable;
	int wstatus, i = 0, ret; /*background programs flag*/
	pid_t pid;

	if (!builtin_command(argv, status))/*execute built-in OR block*/
	{
		for (; (pathname[i] = argv[0][i]) != '\0'; i++)
			;/*search for the executable in the PATH*/
		pathname[i] = '\0';
		/*printf("pathname: %s\n", pathname);*/
		file = get_file(pathname);
		executable = parse_path(&head, file);
		if (executable)/*argv[0] = file to search*/
		{
			if (argv[1] && argv[1][0] == '$')/*i.e if variable_substitution*/
				variable_substitute(argv, status);
			pid = Fork();
			if (pid == 0)
			{/* Child runs the user job (cmdline) */
				if (execve(executable, argv, environ) < 0)/*error occurred(-1) returned */
					unix_error("execve error"), exit(1);
			}
			/*parent waits for foreground job to terminate*/
			if (!bg) /* i.e. if a foreground process (bg = 0)*/
			{
				ret = waitpid(pid, &wstatus, 0);
				if (ret < 0)/*wait for termination(fg_job) & reap*/
					unix_error("wait_fg: waitpid error");
				if (WIFEXITED(wstatus))
				{
					/*set_success(WEXITSTATUS(wstatus));*/
					*status = WEXITSTATUS(wstatus);
				}
			}
			else/* its a bg job (bg = 1), continue - no waiting or reaping!*/
				_write(buf, "background job", ": parent free to continue...\n");
		}
		else
			_write(buf, argv[0], ": executable not found.\n");
	}
}

/**
 * evaluate_command_line - evaluate the cmdline
 * i.e. the string/cmd typed/read from stdin
 * @cmdline: the command to evaluate
 * @head: head to path_dirs linked list
 * Return: Nothing
 */
void evaluate_command_line(char *cmdline, d_t *head)
{
	char *argv[MAXARGS], buf[MAXLINE], del = ' ', delims[PATH_S], command[PATH_S];
	char *commands[MAXARGS];
	int bg, i, j, _success = 0, *status = &_success; /*progs & success flag*/

	_strcpy(buf, cmdline); /*cpy cmdline into buf*/
	/*determine no of commands in line, and for each, run through this process*/
	handle_comments(buf);/*remove everything starting at # - usually ignored*/
	check_for_delims(buf, "&|;", delims);
	/*printf("check delims done\n");*/
	if (_strlen(delims))/*delimiters present, more than one command*/
	{
		for (i = 0; delims[i] != '\0'; i++)
		{
			bg = parse_line(buf, commands, delims[i]);/*return (array) of commands*/
			if (commands[0] == NULL)
				return; /*Ignore empty cmd lines*/
			/* get individual command argv(s) and evaluate */
			for (j = 0; commands[j] != NULL; j++)
			{
				format_command(commands[j], command);
				if (j < 1 || (j > 0 && ((delims[i] == '&' && !_success) ||
					(delims[i] == '|' && _success))) || delims[i] == ';')
				{
					_strcpy(buf, command);
					bg = parse_line(buf, argv, del);
					if (argv[0] == NULL)
					return; /*Ignore empty cmd - is that a possibility though?*/
					evaluate_command(argv, head, bg, status);
				}
			}
		}
	}
	else
	{/*else, a single command or ALIAS */
		bg = parse_line(buf, argv, del);/*returns argv for command*/
		if (argv[0] == NULL)
			return; /*Ignore empty cmd lines*/
		evaluate_command(argv, head, bg, status);
	}
}


