#include "main.h"

int main(int ac, char **av, char **env)
{
	/*address of env and environ*/
	(void)ac, (void)av;
	printf("env: %p\n", (void *)env);
	printf("environ: %p\n", (void *)environ);
}

