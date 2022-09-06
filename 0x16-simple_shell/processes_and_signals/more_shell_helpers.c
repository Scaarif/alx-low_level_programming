#include "main.h"

/**
 * variable_substitute - implement variable replacement
 * & update exit status
 * @argv: pointer to command args
 * @status: exit status flag
 * Return: Nothing
 */
void variable_substitute(char **argv, int *status)
{
	int i = 0;
	char buf[20], *var, name[100];
	res _res = {-1, -1}, *res = &_res;

	/* handle env values, ppid and exit status*/
	if (argv[1][1] == '$')
	{
		_ltoa((long)getpid(), buf, 10);
		for (; (argv[1][i] = buf[i]) != '\0'; i++)
			;
		argv[1][i] = '\0';/*update argv[1] to pid_str*/
	}
	else if (argv[1][1] == '?')
	{
		_ltoa((long)*status, buf, 10);
		for (; (argv[1][i] = buf[i]) != '\0'; i++)
			;
		argv[1][i] = '\0';/*update argv[1] to exit_status*/
	}
	else if (argv[1][1] >= 'A' && argv[1][1] <= 'Z')
	{/* probably an env variable, so check */
		for (; (name[i] = argv[1][i + 1]) != '\0'; i++)
			;
		name[i] = '\0';/*terminate*/
		var = _getenv(environ, name, res);
		if (var)
		{
			for (i = 0; (argv[1][i] = var[i]) != '\0'; i++)
				;
			argv[1][i] = '\0';
		}
		else
			argv[1][0] = '\0';/*should be NULL*/
	}
	else if (argv[1][1] != '(')
	{
		argv[1][0] = '\0';
	}
	/* handle the situation where it's a command! - that's the else */
}


