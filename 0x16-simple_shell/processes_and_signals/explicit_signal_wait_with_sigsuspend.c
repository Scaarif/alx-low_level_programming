#include "main.h"

/** sigsuspend - a non wasteful way to spin wait, faster
 * than sleep() and avoids the potential race introduced by pause
 * Description: suspends the process and temporarily replaces
 * the blocked set with another, unblocking some set & signal(s)
 * until a signal is received, either terminating a process or
 * invoking a handler. If the former, sigsupend does not return.
 * In the latter case, sigsuspend returns after restoring the blocked
 * set, in essence reblocking what'd been temporarily unblocked!
 */

volatile sig_atomic_t pid;

void sigchld_handler(int s)
{
	(void)s;
	int olderrno = errno;
	pid = waitpid(-1, NULL, 0);/*set the global variable pid (non-zero)*/
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
		if (i > 1)
			printf("%d reset to 0.\n", pid);
		pid = 0; /*set flag to 0*/
		Sigprocmask(SIG_SETMASK, &prev, NULL);/*unblock SIGCHLD*/
		/*wait for SIGCHLD to be received (non-wasteful)*/
		while (!pid)/*i.e wait until pid is non-zero for this to evaluate to false*/
			sigsuspend(&prev);
		/*Do some work after receiving SIGCHLD*/
		printf("Doing some followup work...\n");
	}
	exit(0);
}

