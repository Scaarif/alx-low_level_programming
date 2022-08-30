#include "main.h"

/**
 * Race_and_signala - this code is buggy as it results in a race
 * Description: the race is between addjob and deletejob
 * If deletejob wins (is executed before addjob), the code is wrong
 * otherwise, the code is right (addjob scheduled before deletejob)
 * Scheduling: done by the kernel - could decide to schedule the child
 * on Fork() before the parent in which case the child terminates and
 * a SIGCHLD signal's sent to the parent. The kernel might then force
 * the parent to receive the signal before adding the child to job
 * in which case the child is reaped 
 * deletejob will in this case then delete a non-existent child in list
 * (was never added) and the addjob has no child to add(as it no longer
 * exists)
 * Race - due to the non-deterministic nature of interleaving (schedules)
 * a solution: use signal blocking as in v2
 */

void initjobs()
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
	sigset_t mask_all, prev_all;

	Sigfillset(&mask_all);
	Signal(SIGCHLD, handler);/*sigaction - specify handling semantics*/
	initjobs();/*initialize the job list*/
	while (1)/*infinite loop*/
	{
		pid = Fork();
		if (pid == 0)
			Execve("/bin/date", argv, NULL);
		Sigprocmask(SIG_BLOCK, &mask_all, &prev_all);/*parent*/
		addjob(pid); /*add the child to the job list*/
		Sigprocmask(SIG_SETMASK, &prev_all, NULL);
	}
	exit(0);
}

