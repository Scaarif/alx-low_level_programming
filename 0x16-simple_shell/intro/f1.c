#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>

/*unix_error - error reporting function, unix-style*/
void unix_error(char *msg)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));/*defined in string.h*/
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
	Fork();/*creates two processes, parent and child*/
	Fork();/*another two, from the two calling processes above*/
	printf("Hello\n");/*total - 4 processes running*/
	exit(0);/*defined in stdlib*/
}

