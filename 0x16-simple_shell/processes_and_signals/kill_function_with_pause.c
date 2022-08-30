#include "main.h"

int main(void)
{
	pid_t pid;

	/*child sleeps until SIGKILL signal is received, then dies*/
	pid = Fork();
	if (pid == 0)
	{
		printf("(child) about to receive signal\n");
		pause(); /*wait for a signal*/
		printf("control should never reach here.\n");
		exit(0);
	}
	/*Parent sends a SIGKILL signal to a child*/
	printf("Waiting for a signal, send it!\n");
	/*Kill(pid, SIGKILL);*/
	printf("sent\n");
	exit(0);
}


