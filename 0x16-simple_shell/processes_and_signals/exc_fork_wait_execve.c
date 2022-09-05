#include "main.h"

#define N 5

/**
 * main - creates a cild process
 * executes ls -l /tmp via child
 * waits for the child to terminate, reaps it
 * then craetes another child, to do the same
 * @argc: no of args
 * @argv: the cmd-line args array of strings
 * Return: 0 always
 */

int main(__attribute__((unused))int argc, char **argv)
{
	int i = 0, wstatus, w;
	pid_t pid;

	for (; i < N; i++)
	{
		/* create a child */
		pid = Fork();
		if (pid == 0)/* if child_p */
		{
			printf("Child %d executing:\n", i);
			Execve("/bin/ls", argv, NULL);
		}
		/* wait for child to terminate & reap zombie */
		w = waitpid(pid, &wstatus, WUNTRACED | WCONTINUED);
		if (w == -1)/*error*/
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
		if (WIFEXITED(wstatus))
			printf("exited, status=%d\n", WEXITSTATUS(wstatus));
		else if (WIFSIGNALED(wstatus))
			printf("killed by signal %d\n", WTERMSIG(wstatus));
		else if (WIFSTOPPED(wstatus))
			printf("stopped by signal %d\n", WSTOPSIG(wstatus));
		else if (WIFCONTINUED(wstatus))
			printf("continued\n");
		printf("Child %d reaped!\n", i);
		/*create another child - via loop */
	}
	exit(0);/*terminate parent*/
}


