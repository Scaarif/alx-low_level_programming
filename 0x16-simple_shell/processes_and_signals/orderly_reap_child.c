#include "main.h"

#define N 2

/**
 * main - reap zombie children in the order they were created
 * Return: 0 always
 */
int main(void)
{
	int status, i;
	pid_t pid[N], retpid;

	/* Parent creates N children */
	for (i = 0; i < N; i++)
	{
		pid[i] = Fork();
		if (pid[i] == 0)/*a Child*/
			exit(100 + i);/*terminate*/
	}
	/* Reap N children (zombies) in no particular order - all in wait set */
	i = 0;
	while ((retpid = waitpid(pid[i++], &status, 0)) > 0)
	{
		if (WIFEXITED(status))
			printf("child %d terminated normally with exit status=%d\n",
					retpid, WEXITSTATUS(status));
		else
			printf("child %d terminated abnormally\n", retpid);
	}
	/*only an error(-1) can get us out of the loop - is it ECHILD?*/
	if (errno != ECHILD)
		unix_error("waitpid error");
	/*i.e notify if some other error, other than no more children, resulted*/
	exit(0);
}

