#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

/**
 * main - fork & wait example
 *
 * Return: always 0
 */
int main(void)
{
	pid_t child_pid;
	int status;

	child_pid = fork();/*returns child pid to parent and 0 to child?*/
	if (child_pid == -1)
	{
		perror("Error");
		return (1);
	}
	if (child_pid == 0)
	{
		printf("Wait for me, wait for me\n");
		sleep(3);
	}
	else
	{
		wait(&status);
		printf("Oh, it's all better now\n");
	}
	return (0);
}

