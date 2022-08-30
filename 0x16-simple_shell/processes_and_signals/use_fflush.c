#include "main.h"

/**
 * main - reap a child process
 * Return: 0 Always
 */

int main(void)
{
	if (Fork() == 0)
	{
		printf("9");
		fflush(stdout);
	}
	else
	{/*Parent*/
		printf("0");
		fflush(stdout);
		waitpid(-1, NULL, 0);
	}
	printf("3");
	fflush(stdout);
	printf("6");
	exit(0);
}


