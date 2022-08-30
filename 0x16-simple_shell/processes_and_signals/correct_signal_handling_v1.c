#include "main.h"

#define MAXBUF 1024

/* this version is buggy - assumes signals are queued */

/**
 * handler1 - catches signal
 * @sig: the signal to catch (modify default behavior)
 * Return: Nothing
 */
void handler1(int sig)
{
	(void)sig; /*unused arg*/
	int olderrno = errno; /*save errno, the safe option*/

	if ((waitpid(-1, NULL, 0)) < 0) /*error*/
		sio_error("waitpid error");
	Sio_puts("Handler reaped child\n");
	Sleep(1);
	errno = olderrno;
}

int main(void)
{
	int i, n;
	char buf[MAXBUF];

	/*catch SIGCHLD signal and reap a child, instead of (default) ignoring it*/
	if (signal(SIGCHLD, handler1) == SIG_ERR)
		unix_error("signal error");
	/* parent creates children */
	for (i = 0; i < 3; i++)
	{
		if (Fork() == 0)
		{
			printf("Hello from child %d\n", (int)getpid());
			exit(0);/*terminate child - send SIGCHLD signal to parent*/
		}
	}
	/* parent waits for terminal input, then processes it */
	n = read(STDIN_FILENO, buf, sizeof(buf));
	if (n < 0)/*error*/
		unix_error("read");
	/*while this line & n are unrelated, this line executes after read */
	printf("Parent processing input\n");
	/*(just coz of the top-down order of execution) and nothing else*/
	while (1)
		;/*infinite loop - so we'd need to terminate via some signal*/
	exit(0);
}

