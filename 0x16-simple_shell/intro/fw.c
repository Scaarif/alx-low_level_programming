#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

/*unix_error - error reporting function, unix-style*/
void unix_error(char *msg)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	exit(0);
}

/**
 *  Fork - error handling wrapper for the system fn, fork()
 *  has identical args as base fn, with the first letter capitalized
 *  calls base fn, checks for errors and terminates if any
 *  Return; PID
 */
pid_t Fork(void)
{
	pid_t pid;

	if ((pid = fork()) < 0)
		unix_error("Fork error");
	return (pid);
}


int main(void)
{
	if (Fork() == 0)/*child*/
	{
		printf("9");
		fflush(stdout);/*clear/flush stream*/
	}
	else/*parent*/
	{
		printf("0"); fflush(stdout);
		waitpid(-1, NULL, 0);
	}/*both*/
	printf("3"); fflush(stdout);
	printf("6\n"); exit(0);
}

