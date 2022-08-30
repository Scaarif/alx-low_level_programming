#include <stdio.h>
#include <unistd.h>

/**
 * main - fork example
 *
 * Return: always 0
 */
int main(void)
{
	pid_t my_pid, pid;

	printf("Before fork\n");
	pid = fork();/*returns child pid to parent and 0 to child?*/
	if (pid == -1)
	{
		perror("Error");
		return (1);
	}
	printf("After fork\n");
	my_pid = getpid();
	printf("My pid is %u\n", my_pid);
	return (0);
}

