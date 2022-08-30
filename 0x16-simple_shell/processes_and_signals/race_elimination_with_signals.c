#include "main.h"

volatile int counter = 0;

/**
 * Race Elimination - eliminating the race in v1
 * block SIGCHLD signals before the call to fork()
 * unblock them only after addingjob (adding child to list)
 * NOTE: children inherit the blocked set of their parents
 * we must therefore be careful to unblock the SIGCHLD in the child
 * before calling execve.
 * SIGCHLD is only unblocked after addjob(), hence deletejob() can
 * never happen before addjob() (its only handled after its unblocked)
 */

void initjobs(void)
{
	printf("jobs initialized!\n");
}

void addjob(int pid)
{
	printf("%d added\n", pid);
}

void deletejob(int pid)
{
	printf("%d deleted\n", pid);
	printf("%d children\n", ++counter);
}

/**
 * handler - catch the signal (modify default behavior)
 * @sig: the signal to catch
 * Return: Nothing
 */
void handler(__attribute__((unused))int sig)
{
	int olderrno = errno; /*save to later restore*/
	sigset_t mask_all, prev_all;
	int pid;

	Sigfillset(&mask_all);/*add all signals to mask set*/
	/*wait for termination, reap child and delete it from job list*/
	while ((pid = waitpid(-1, NULL, 0)) > 0)
	{
		Sigprocmask(SIG_BLOCK, &mask_all, &prev_all);/*block sets*/
		deletejob(pid);/*delete the child from job list - unaffected by signal*/
		Sigprocmask(SIG_SETMASK, &prev_all, NULL);/*unblock mask*/
	}
	if (errno != ECHILD)
		sio_error("waitpid");
	errno = olderrno;/*restore saved errno - safe option*/
}

/**
 * main - signal blocking and race example
 * @argc: no of cmd_line args
 * @argv: array of arg strings
 * Return: 0 always
 */
int main(int argc, char **argv)
{
	(void)argc;/* unused */
	int pid;
	sigset_t mask_all, prev_all, mask_one;

	Sigfillset(&mask_all);/*add all signals to this set*/
	Sigemptyset(&mask_one);/*initialize an empty set, mask_one*/
	Sigaddset(&mask_one, SIGCHLD);/*add SIGCHLD to set, mask_one*/
	Signal(SIGCHLD, handler);/*sigaction - specify handling semantics*/
	initjobs();/*initialize the job list*/
	while (1)/*infinite loop*/
	{/*Block SIGCHLD*/
		Sigprocmask(SIG_BLOCK, &mask_one, &prev_all);
		pid = Fork();
		if (pid == 0)/* child process */
		{/*unblock SIGCHLD in child - inherits blocked sets*/
			Sigprocmask(SIG_SETMASK, &prev_all, NULL);
			Execve("/bin/date", argv, NULL);
		}
		/* parent process */
		Sigprocmask(SIG_BLOCK, &mask_all, &prev_all);/*block*/
		addjob(pid); /*add the child to list uninterrupted*/
		Sigprocmask(SIG_SETMASK, &prev_all, NULL);/*unblock all*/
	}
	printf("counter: %d\n", counter);
	exit(0);
}

