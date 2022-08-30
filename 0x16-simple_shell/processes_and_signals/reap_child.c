#include "main.h"

#define N 2

/**
 * main - reap zombie children
 * Return: 0 always
 */
int main(void)
{
	int status, i;
	pid_t pid;

	/* Parent creates N children */
	for (i = 0; i < N; i++)
	{
		pid = Fork();
		if (pid == 0)/*a Child*/
			exit(100 + i);/*terminate*/
	}
	/* Reap N children (zombies) in no particular order - all in wait set */
	while ((pid = waitpid(-1, &status, 0)) > 0)
	{
		if (WIFEXITED(status))
			printf("child %d terminated normally with exit status=%d\n",
					pid, WEXITSTATUS(status));
		else
			printf("child %d terminated abnormally\n", pid);
	}
	/*only an error(-1) can get us out of the loop - is it ECHILD?*/
	if (errno != ECHILD)
		unix_error("waitpid error");
	/*i.e notify if some other error, other than no more children, resulted*/
	exit(0);
}

