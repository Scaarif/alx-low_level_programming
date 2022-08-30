#include "main.h"

volatile sig_atomic_t pid;

void sigchld_handler(int s)
{
	(void)s;
	int olderrno = errno;
	pid = waitpid(-1, NULL, 0);/*set the global variable*/
	printf("%d reaped.\n", pid);
	errno = olderrno;
}

/*void sigint_handler(__attribute__((unused))int s)*/
/*{*/
/*}*/

int main(void)
{
	sigset_t mask, prev;
	int i = 0;

	Signal(SIGCHLD, sigchld_handler);
	Signal(SIGINT, sigint_handler);
	Sigemptyset(&mask);
	Sigaddset(&mask, SIGCHLD);

	while (i++ < 10)
	{
		Sigprocmask(SIG_BLOCK, &mask, &prev);/*block SIGCHLD*/
		if (Fork() == 0)
			exit(0);/*terminate*/
		/* parent */
		printf("%d reset to 0.\n", pid);
		pid = 0; /*set flag to 0*/
		Sigprocmask(SIG_SETMASK, &prev, NULL);/*unblock SIGCHLD*/
		/*wait for SIGCHLD to be received (wasteful)*/
		while (!pid)
			;
		/*Do some work after receiving SIGCHLD*/
		printf("Doing some followup work...\n");
	}
	exit(0);
}

