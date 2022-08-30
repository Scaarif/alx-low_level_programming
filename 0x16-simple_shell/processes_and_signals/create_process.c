#include "main.h"

/**
 * main - create a child process
 * Return: 0 Always
 */

int main(void)
{
	pid_t pid;
	int x = 1;

	pid = Fork();
	if (pid == 0)
	{
		printf("child: x=%d\n", ++x);
		exit(0);
	}
	/*Parent*/
	printf("parent: x=%d\n", --x);
	exit(0);
}


