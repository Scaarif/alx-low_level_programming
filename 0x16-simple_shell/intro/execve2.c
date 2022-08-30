#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv, char **envp)
{
	int i;
	(void) argc;

	printf("Command-line arguments:\n");
	for(i = 0; argv[i] != NULL; i++)
		printf(" argv[%d]: %s\n", i, argv[i]);
	printf("\n");
	printf("Environment variables:\n");
	for (i = 0; envp[i] != NULL; i++)
		printf(" envp[%d]: %s\n", i, envp[i]);
	return (0);
}

