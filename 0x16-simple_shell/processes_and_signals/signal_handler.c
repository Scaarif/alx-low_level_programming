#include "main.h"

/**
 * main - catch SIGINT signal (Ctrl + c)
 * usually(default) terminates the process immediately
 * here, we modify the default behavior to catch the signal
 * print a message, then terminate the process
 * Return: always 0
 */
int main(void)
{
	/*install the SIGINT handler - using signal function*/
	if (signal(SIGINT, sigint_handler) == SIG_ERR)
		unix_error("signal error");
	printf("Ok, I'm waiting for a SIGINT signal. C'mon, type it in...\n");
	pause(); /*wait for the signal*/
	return (0);
}


