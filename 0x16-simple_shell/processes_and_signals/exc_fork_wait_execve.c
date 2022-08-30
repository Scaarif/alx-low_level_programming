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
	int i = 0;

	for (; i < N; i++)
	{
		/* create a child */
		if (Fork() == 0)/* if child_p */
		{
			printf("Child %d executing:\n", i);
			Execve("/bin/ls", argv, NULL);
		}
		/* wait for child to terminate & reap zombie */
		if (waitpid(-1, NULL, 0) < 0)
			unix_error("waitpid error");
		printf("Child %d reaped!\n", i);
		/*create another child - via loop */
	}
	exit(0);/*terminate parent*/
}


