#include "main.h"

/**
 * main - simple_shell's main routine
 * Return: 0 always
 */
int main(void)
{
	char cmdline[MAXLINE]; /*the command(line)*/

	while (1) /*infinite loop - only terminates if feof/builtin_command evaluates to true*/
	{
		/* Read cmd from stdin */
		printf("#cisfun$ ");
		Fgets(cmdline, MAXLINE, stdin);
		if (feof(stdin))/*checks EOF status and returns 1 if set*/
			exit(0);
		/* Evaluate the cmd */
		evaluate_command(cmdline);
		/*update environ here? update PWD and OLDPWD*/
		/*setenv("PWD", pwd, 1);*/
		/*setenv("OLDPWD", old_pwd, 1);*/
	}
}