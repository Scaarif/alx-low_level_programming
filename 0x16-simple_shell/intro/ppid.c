#include <stdio.h>
#include <unistd.h>

/**
 * main - PID, process ID
 * Return: always 0
 */
int main(void)
{
	pid_t my_pid, my_ppid;

	my_pid = getpid();
	my_ppid = getppid();
	printf("parent: %u & child: ", my_ppid);
	printf("%u\n", my_pid);
	return (0);
}

