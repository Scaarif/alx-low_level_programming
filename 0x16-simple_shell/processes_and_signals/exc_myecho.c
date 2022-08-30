#include "main.h"

int main(int argc, char **argv, char **envp)
{
	int i;

	if (argc < 2)
	{
		printf("Error: Usage %s agv[1] ...\n", argv[0]);
		return (1);
	}
	printf("Cmd-line args:\n");
	for (i = 0; i < argc; i++)
		printf("%s\n", argv[i]);
	printf("Environment variables:\n");
	for (i = 0; envp[i] != NULL; i++)
		printf("%s\n", envp[i]);
	return (0);
}

