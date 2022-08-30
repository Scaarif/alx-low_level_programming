#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	char *newargv[] = {NULL, "hello", "world", NULL};
	char *newenviron[] = { NULL };

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file_to_exec>\n", argv[0]);
		exit(EXIT_FAILURE);/*symbolic constant: POSIX std*/
	}

	newargv[0] = argv[1];/*reassign pathname to file_to_exec*/
	/*int execve(const char *pathname, char *const argv[], char *const envp[])*/
	execve(argv[1], newargv, newenviron);/*pathname = name of file_to_exec = argv[1]*/
	perror("execve"); /*execve() returns only an error*/
	exit(EXIT_FAILURE);
}

