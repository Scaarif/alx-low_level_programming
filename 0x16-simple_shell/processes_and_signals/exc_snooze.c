#include "main.h"

/*alternative sigint_handler*/
void handle_sigint(int sig)
{
	(void)sig;
	/*catches the signal by returning (to wakeup) instead of terminating*/
	return;
}

int main(int argc, char **argv)
{
	if (argc < 2)
		printf("Error: Usage %s <secs>\n", argv[0]), exit(0);
	if (signal(SIGINT, handle_sigint) == SIG_ERR)
		unix_error("signal error");
	wakeup(atoi(argv[1]));/*sleep for that much time*/
	return (0);
}


